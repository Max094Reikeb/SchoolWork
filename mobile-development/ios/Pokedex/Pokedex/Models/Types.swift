//
//  Types.swift
//  Pokedex
//
//  Created by Maxence Bekier on 09/02/2024.
//

import Foundation
import SwiftUI

struct PokemonTypes: Codable, Hashable {
    var slot: Int
    var type: PokemonType
}

struct PokemonType: Codable, Hashable {
    var name: String
}

extension PokemonTypes {
    static var preview = PokemonTypes(slot: 1, type: .preview)
}

extension PokemonType {
    static var preview = PokemonType(name: "fire")
}

enum Types: String, CaseIterable {
    case normal, fighting, flying, poison, ground, rock, bug, ghost, steel, fire, water, grass, electric, psychic, ice, dragon, dark, fairy
    
    private static let colorsPart1: [Color] = [
        Color.gray, Color.orange, Color.blue.opacity(0.5), Color.purple, Color.orange.opacity(0.5), Color.brown
    ]
    
    private static let colorsPart2: [Color] = [
        Color.green.opacity(0.5), Color.purple.opacity(0.5), Color.gray.opacity(0.8), Color.red, Color.blue
    ]
    
    private static let colorsPart3: [Color] = [
        Color.green, Color.yellow, Color.pink, Color.cyan, Color.black, Color.black, Color.pink.opacity(0.5)
    ]
    
    private static let colors = colorsPart1 + colorsPart2 + colorsPart3
    
    var color: Color {
        if let index = Types.allCases.firstIndex(of: self) {
            return Types.colors[index % Types.colors.count]
        }
        return .white
    }
}

extension Types {
    static func color(forTypeName typeName: String) -> Color {
        guard let type = Types(rawValue: typeName.lowercased()) else {
            return .white
        }
        return type.color
    }
}
