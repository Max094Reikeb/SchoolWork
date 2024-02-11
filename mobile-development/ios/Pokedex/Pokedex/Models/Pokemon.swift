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
    var height: Int
    var weight: Int
    var base_experience: Int
    var abilities: [Abilities]
    var sprites: Sprite
    var game_indices: [Games]
    var moves: [Moves]
    var types: [PokemonTypes]
}

extension PokemonLink {
    static var preview = PokemonLink(name: "charizard", url: Sprite.preview.front_default)
}

extension Pokemon {
    static var preview = Pokemon(name: "charizard", id: 6, height: 45, weight: 895, base_experience: 128, abilities: [.preview], sprites: Sprite.preview, game_indices: [.preview], moves: [.preview], types: [.preview])
}
