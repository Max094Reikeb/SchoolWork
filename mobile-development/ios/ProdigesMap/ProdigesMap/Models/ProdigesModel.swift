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
    
    var currentListener: ListenerRegistration?
    @ObservationIgnored var currentId: String? {
        didSet {
            if let listener = currentListener {
                listener.remove()
                currentListener = nil
            }
            guard let currentId = currentId else { return }
            
            currentListener = prodigesCollection.document(currentId).addSnapshotListener { querySnapshot, error in
                let prodige = try? querySnapshot?.data(as: Prodige.self)
                self.currentProdige = prodige
                UserDefaults.standard.set(currentId, forKey: "currentId")
            }
        }
    }
    
    override init() {
        super.init()
        
        manager.delegate = self
        manager.requestWhenInUseAuthorization()
        
        setupCurrentProdige()
        trackProdiges()
    }
    
    func setupCurrentProdige() {
        currentId = UserDefaults.standard.string(forKey: "currentId")
    }
}

extension ProdigesModel: CLLocationManagerDelegate {
    func locationManagerDidChangeAuthorization(_ manager: CLLocationManager) {
        print("\(manager.authorizationStatus)")
        if manager.authorizationStatus == .authorizedWhenInUse {
            locationUpdates()
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
                
                let futureEvents = await monitor.events
                let allEvents = switch initialEvent {
                case .some(let initialEvent): chain(AsyncJustSequence(initialEvent), futureEvents).eraseToAnyAsyncSequence()
                case .none: futureEvents.eraseToAnyAsyncSequence()
                }

                for try await event in allEvents {
                    guard let currentId else { return }
                    let tracked = switch event.state {
                    case .satisfied: true
                    default: false
                    }
                    updateProdige(id: currentId, values: ["tracked": tracked])
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
                if let currentId, let currentProdige, currentProdige.tracked {
                    if let location = update.location {
                        print(location)
                        let position = GeoPoint(latitude: location.coordinate.latitude, longitude: location.coordinate.longitude)
                        updateProdige(id: currentId, values: ["position": position])
                    }
                }
            }
        }
    }
    
    func updateProdige(id: String, values: [AnyHashable: Any]) {
        prodigesCollection.document(id).updateData(values)
    }
}
