//
//  ProdigesModel.swift
//  ProdigesMap
//
//  Created by Maxence Bekier on 31/01/2024.
//

import CoreLocation
import Foundation

class ProdigesModel {
    static let shared = ProdigesModel()
    let center = CLLocationCoordinate2D(latitude: 48.9355351, longitude: 2.3030026)
    private let manager = CLLocationManager()
    
    init() {
        manager.requestWhenInUseAuthorization()
        
        Task {
            let monitor = await CLMonitor("monitorName")
            let condition = CLMonitor.CircularGeographicCondition(center: center, radius: 50)
            await monitor.add(condition, identifier: "Condition")
            
            for try await event in await monitor.events {
                print("Monitor event: \(event)")
            }
        }
    }
}
