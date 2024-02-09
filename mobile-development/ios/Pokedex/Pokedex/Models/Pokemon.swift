//
//  Pokemon.swift
//  Pokedex
//
//  Created by Maxence Bekier on 08/02/2024.
//

import Foundation

struct PokemonLink: Codable, Hashable {
    var name: String
    var url: String
}

struct Pokemon: Codable, Hashable {
    var name: String
    var id: Int
    var sprites: Sprite
    var game_indices: [Games]
    var moves: [Moves]
    var types: [PokemonTypes]
}

struct PokemonTypes: Codable, Hashable {
    var slot: Int
    var type: PokemonType
}

struct PokemonType: Codable, Hashable {
    var name: String
}

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

extension PokemonLink {
    static var preview = PokemonLink(name: "pecharunt", url: "https://raw.githubusercontent.com/PokeAPI/sprites/master/sprites/pokemon/1025.png")
}

extension Games {
    static let preview = Games(game_index: 1, version: Version.preview)
}

extension Version {
    static let preview = Version(name: "red")
}
