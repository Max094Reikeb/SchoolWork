//
//  AppDelegate.swift
//  ProdigesMap
//
//  Created by Maxence Bekier on 02/02/2024.
//

import FirebaseCore
import Foundation
import SwiftUI

class AppDelegate: NSObject, UIApplicationDelegate {
    func application(_ application: UIApplication,
                     didFinishLaunchingWithOptions launchOptions: [UIApplication.LaunchOptionsKey : Any]? = nil) -> Bool {
        FirebaseApp.configure()
        return true
    }
}
