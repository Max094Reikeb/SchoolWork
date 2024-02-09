//
//  Moves.swift
//  Pokedex
//
//  Created by Maxence Bekier on 09/02/2024.
//

import Foundation

struct MoveLink: Codable, Hashable {
    var name: String
    var url: String
}

struct Moves: Codable, Hashable {
    var move: MoveLink
}

struct Move: Codable, Hashable {
    var type: MoveType
}

struct MoveType: Codable, Hashable {
    var name: String
}

extension Moves {
    static let preview = Moves(move: .preview)
}

extension MoveLink {
    static let preview = MoveLink(name: "razor-wind", url: "https://pokeapi.co/api/v2/move/13/")
}
