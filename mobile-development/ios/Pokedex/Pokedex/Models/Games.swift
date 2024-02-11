//
//  Games.swift
//  Pokedex
//
//  Created by Maxence Bekier on 09/02/2024.
//

import Foundation

struct Games: Codable, Hashable {
    var game_index: Int
    var version: Version
}

struct Version: Codable, Hashable {
    var name: String
}

struct Sprite: Codable, Hashable {
    var front_default: String
}

extension Games {
    static let preview = Games(game_index: 1, version: Version.preview)
}

extension Version {
    static let preview = Version(name: "red")
}

extension Sprite {
    static let preview = Sprite(front_default: "https://raw.githubusercontent.com/PokeAPI/sprites/master/sprites/pokemon/6.png")
}
