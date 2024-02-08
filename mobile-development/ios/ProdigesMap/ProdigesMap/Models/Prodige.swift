//
//  Prodige.swift
//  ProdigesMap
//
//  Created by Maxence Bekier on 02/02/2024.
//

import FirebaseFirestore
import Foundation

struct Prodige: Identifiable, Codable, Equatable {
    @DocumentID var id: String?
    let name: String
    let password: String
    let position: GeoPoint
    let tracked: Bool
}
