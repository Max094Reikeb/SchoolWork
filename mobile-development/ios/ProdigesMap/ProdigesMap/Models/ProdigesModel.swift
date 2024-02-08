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
import UserNotifications

@Observable
class ProdigesModel: NSObject {
    
    var currentProdige: Prodige?
    var prodiges = [Prodige]()
    var trackedProdiges: [Prodige] { prodiges.filter(\.tracked) }
    var monitor: CLMonitor?
    var initialEvent: CLMonitor.Event?
    
    let prodigesCollection = Firestore.firestore().collection("prodiges")
    static let shared = ProdigesModel()
    let center = CLLocationCoordinate2D(latitude: 48.9355351, longitude: 2.3030026)
    private let manager = CLLocationManager()
    private var updateTask: Task<(), Error>?
    private var notificationAuthorized = false
    
    var currentListener: ListenerRegistration?
    @ObservationIgnored var currentId: String? {
        didSet {
            if let listener = currentListener {
                listener.remove()
                currentListener = nil
            }
            Task {
                await updateProdigeTracking()
            }
            guard let currentId = currentId else {
                currentProdige = nil
                UserDefaults.standard.removeObject(forKey: "currentId")
                return
            }
            
            currentListener = prodigesCollection.document(currentId).addSnapshotListener { querySnapshot, error in
                let prodige = try? querySnapshot?.data(as: Prodige.self)
                self.currentProdige = prodige
                UserDefaults.standard.set(currentId, forKey: "currentId")
            }
        }
    }
    
    override init() {
        super.init()
        
        initNotifications()
        manager.delegate = self
        manager.requestAlwaysAuthorization()
        
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
        if [.authorizedAlways, .authorizedWhenInUse].contains(manager.authorizationStatus) {
            if let _ = monitor { return }
            Task {
                monitor = await CLMonitor("monitorName")
                let condition = CLMonitor.CircularGeographicCondition(center: center, radius: 2000)
                await monitor?.add(condition, identifier: "Condition")
                
                await updateProdigeTracking()
            }
        }
    }
    
    func updateProdigeTracking() async {
        guard let _ = monitor else { return }
        
        let identifiers = await monitor!.identifiers
        for identifier in identifiers {
            if let record = await monitor!.record(for: identifier) {
                initialEvent = record.lastEvent
            }
        }
        
        let futureEvents = await monitor!.events
        let allEvents = switch initialEvent {
        case .some(let initialEvent): chain(AsyncJustSequence(initialEvent), futureEvents).eraseToAnyAsyncSequence()
        case .none: futureEvents.eraseToAnyAsyncSequence()
        }
        
        do {
            for try await event in allEvents {
                guard let currentId else { break }
                let tracked = switch event.state {
                case .satisfied: true
                default: false
                }
                updateProdige(id: currentId, values: ["tracked": tracked])
                tracked ? startLocationUpdates() : stopLocationUpdates()
            }
        } catch {
            print("Error iterating over events: \(error)")
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
    
    func startLocationUpdates() {
        displayUpdateNotification(.localisationUpdateStarted)
        updateTask = Task {
            let updates = CLLocationUpdate.liveUpdates()
            for try await update in updates {
                guard let currentId else { continue }
                
                if let location = update.location {
                    print(location)
                    let position = GeoPoint(latitude: location.coordinate.latitude, longitude: location.coordinate.longitude)
                    updateProdige(id: currentId, values: ["position": position])
                }
                
            }
        }
    }
    
    func stopLocationUpdates() {
        displayUpdateNotification(.localisationUpdateStopped)
        updateTask?.cancel()
        updateTask = .none
    }
    
    func updateProdige(id: String, values: [AnyHashable: Any]) {
        prodigesCollection.document(id).updateData(values)
    }
    
    func initNotifications() {
        UNUserNotificationCenter.current().requestAuthorization(options: [.alert, .sound, .badge]) { result, error in
            self.notificationAuthorized = result
        }
    }
    
    func displayUpdateNotification(_ notification: ProdigesModel.Notification) {
        Task {
            repeat {} while !notificationAuthorized
            let trigger = UNTimeIntervalNotificationTrigger(timeInterval: 0.1, repeats: false)
            let notificationContent = UNMutableNotificationContent()
            notificationContent.title = notification.title
            notificationContent.body = notification.body
            let request = UNNotificationRequest(identifier: notification.identifier, content: notificationContent, trigger: trigger)
            let _ = try await UNUserNotificationCenter.current().add(request)
        }
    }
    
    enum Notification: String, CaseIterable {
        case localisationUpdateStarted
        case localisationUpdateStopped
        
        var identifier: String {
            switch self {
            case .localisationUpdateStarted: "Started"
            case .localisationUpdateStopped: "Ended"
            }
        }
        var title: String {
            "Localisation"
        }
        var body: String {
            switch self {
            case .localisationUpdateStarted: "Votre position est actuellement utilisée parce que vous êtes autour de la Fac."
            case .localisationUpdateStopped: "Votre position n'est plus utilisé parce que vous vous être éloigné de la Fac."
            }
        }
    }
}
