//
//  Item.swift
//  Thursday
//
//  Created by Maxence Bekier on 08/02/2024.
//

import Foundation
import SwiftData

@Model
final class Item {
    var timestamp: Date
    
    init(timestamp: Date) {
        self.timestamp = timestamp
    }
}
