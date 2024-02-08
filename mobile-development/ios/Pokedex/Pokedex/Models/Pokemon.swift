//
//  Pokemon.swift
//  Pokedex
//
//  Created by Maxence Bekier on 08/02/2024.
//

import Foundation

struct Pokemon: Codable {
    var name: String
    var id: Int
    var sprites: Sprite
}

struct Sprite: Codable {
    var front_default: String
}
