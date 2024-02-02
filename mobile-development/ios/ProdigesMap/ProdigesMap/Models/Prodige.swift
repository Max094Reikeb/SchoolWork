//
//  Prodige.swift
//  ProdigesMap
//
//  Created by Maxence Bekier on 02/02/2024.
//

import FirebaseFirestore
import Foundation

struct Prodige: Identifiable, Codable {
    @DocumentID var id: String?
    let name: String
    let position: GeoPoint
    let tracked: Bool
}
