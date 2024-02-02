//
//  ProdigesModel.swift
//  ProdigesMap
//
//  Created by Maxence Bekier on 31/01/2024.
//

import AsyncAlgorithms
import AsyncExtensions
import CoreLocation
import Firebase
import Foundation
import SwiftUI

@Observable
class ProdigesModel: NSObject {
    var name = "User"
    var initialEvent: CLMonitor.Event?
    
    static let shared = ProdigesModel()
    let center = CLLocationCoordinate2D(latitude: 48.9355351, longitude: 2.3030026)
    private let manager = CLLocationManager()
    
    override init() {
        super.init()
        
        manager.delegate = self
        manager.requestWhenInUseAuthorization()
        
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
                    name = stateString
                }
            }
        }
    }
}

extension ProdigesModel {
    func trackProdiges() {
        let db = Firestore.firestore()
        db.collection("prodiges").whereField("tracked", isEqualTo: true)
            .addSnapshotListener { querySnapshot, error in
                guard let documents = querySnapshot?.documents else {
                    print("Error fetching documents: \(error!)")
                    return
                }
                let prodiges = documents.compactMap { $0["name"] }
                print("Tracked Prodiges: \(prodiges)")
            }
    }
}
