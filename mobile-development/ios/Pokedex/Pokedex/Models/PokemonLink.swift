//
//  PokemonLink.swift
//  Pokedex
//
//  Created by Maxence Bekier on 08/02/2024.
//

import Foundation

struct PokemonLink: Codable, Hashable {
    var name: String
    var url: String
}

extension PokemonLink {
    static var preview = PokemonLink(name: "pecharunt", url: "https://raw.githubusercontent.com/PokeAPI/sprites/master/sprites/pokemon/1025.png")
}
