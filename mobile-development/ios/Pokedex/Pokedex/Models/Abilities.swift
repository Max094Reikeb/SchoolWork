//
//  Abilities.swift
//  Pokedex
//
//  Created by Maxence Bekier on 11/02/2024.
//

import Foundation

struct Abilities: Codable, Hashable {
    var ability: Ability
    var slot: Int
}

struct Ability: Codable, Hashable {
    var name: String
}

extension Abilities {
    static var preview = Abilities(ability: .preview, slot: 1)
}

extension Ability {
    static var preview = Ability(name: "chlorophyll")
}
