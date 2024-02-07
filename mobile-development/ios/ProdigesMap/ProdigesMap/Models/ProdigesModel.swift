//
//  ProdigesModel.swift
//  ProdigesMap
//
//  Created by Maxence Bekier on 31/01/2024.
//

import AsyncAlgorithms
import AsyncExtensions
import Combine
import CoreLocation
import Firebase
import Foundation
import SwiftUI

@Observable
class ProdigesModel: NSObject {
    var currentProdige: Prodige?
    var prodiges = [Prodige]()
    var trackedProdiges: [Prodige] { prodiges.filter(\.tracked) }
    var initialEvent: CLMonitor.Event?
    
    let prodigesCollection = Firestore.firestore().collection("prodiges")
    static let shared = ProdigesModel()
    let center = CLLocationCoordinate2D(latitude: 48.9355351, longitude: 2.3030026)
    private let manager = CLLocationManager()
    
    override init() {
        super.init()
        
        manager.delegate = self
        manager.requestWhenInUseAuthorization()
        
        Task {
            var currentListener: ListenerRegistration?
            for await currentId in UserDefaults.standard.observeKey(at: \.currentProdige) {
                switch currentId {
                case .none: print("No current one!")
                case .some(let currentID):
                    if let listener = currentListener {
                        listener.remove()
                        currentListener = nil
                    }
                    currentListener = prodigesCollection.whereField("id", isEqualTo: currentID).addSnapshotListener { querySnapshot, error in
                        guard let documents = querySnapshot?.documents else {
                            print("Error fetching documents: \(error!)")
                            return
                        }
                        do {
                            self.currentProdige = try documents.compactMap { try $0.data(as: Prodige.self) }.first
                        } catch {
                            print("Error deserializing documents: \(error)")
                        }
                        
                    }
                }
            }
        }
        
        trackProdiges()
    }
}

extension ProdigesModel: CLLocationManagerDelegate {
    func locationManagerDidChangeAuthorization(_ manager: CLLocationManager) {
        print("\(manager.authorizationStatus)")
        if manager.authorizationStatus == .authorizedWhenInUse {
            Task {
                let monitor = await CLMonitor("monitorName")
                let condition = CLMonitor.CircularGeographicCondition(center: center, radius: 2000)
                await monitor.add(condition, identifier: "Condition")
                
                let identifiers = await monitor.identifiers
                for identifier in identifiers {
                    if let record = await monitor.record(for: identifier) {
                        initialEvent = record.lastEvent
                    }
                }
                
                let events = await monitor.events
                let allEvents = switch initialEvent {
                case .some(let initialEvent): chain(AsyncJustSequence(initialEvent), events).eraseToAnyAsyncSequence()
                case .none: events.eraseToAnyAsyncSequence()
                }
                
                let stateStrings = allEvents
                    .map { event in
                    return switch event.state {
                    case .unknown: "unknown"
                    case .satisfied: "satisfied"
                    case .unsatisfied: "unsatisfied"
                    case .unmonitored: "unmonitored"
                    @unknown default: "unknown default"
                    }
                }
                for try await stateString in stateStrings {
                    // name = stateString
                }
            }
        }
    }
}

extension ProdigesModel {
    func trackProdiges() {
        prodigesCollection.addSnapshotListener { querySnapshot, error in
            guard let documents = querySnapshot?.documents else {
                print("Error fetching documents: \(error!)")
                return
            }
            do {
                self.prodiges = try documents.compactMap { try $0.data(as: Prodige.self) }
            } catch {
                print("Error deserializing documents: \(error)")
            }
            print("Tracked Prodiges: \(self.prodiges)")
        }
    }
    
    func locationUpdates() {
        Task {
            let updates = CLLocationUpdate.liveUpdates()
            for try await update in updates {
                if let loggedInProdigeId = currentProdige?.id {
                    if let location = update.location {
                        print(location)
                        let position = GeoPoint(latitude: location.coordinate.latitude, longitude: location.coordinate.longitude)
                        updateProdige(id: loggedInProdigeId, values: ["position": position])
                    }
                }
            }
        }
    }
    
    func updateProdige(id: String, values: [AnyHashable: Any]) {
        prodigesCollection.document(id).updateData(values)
    }
}

extension UserDefaults {
    @objc dynamic var currentProdige: String? { string(forKey: "CurrentProdige" )}
    
    typealias AsyncValues<T> = AsyncPublisher<AnyPublisher<T, Never>>
    func observeKey<T>(at path: KeyPath<UserDefaults, T>) -> AsyncValues<T> {
        return self.publisher(for: path, options: [.initial, .new])
            .eraseToAnyPublisher()
            .values
    }

    func setId(_ id: String, forKey key: String) {
        if let encoded = try? JSONEncoder().encode(id) {
            set(encoded, forKey: key)
        }
    }

    func getId(forKey key: String) -> String? {
        if let data = data(forKey: key),
           let id = try? JSONDecoder().decode(String.self, from: data) {
            return id
        }
        return nil
    }
}
