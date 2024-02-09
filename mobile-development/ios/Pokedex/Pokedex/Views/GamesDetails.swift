//
//  GamesDetails.swift
//  Pokedex
//
//  Created by Maxence Bekier on 09/02/2024.
//

import SwiftUI

struct GamesDetails: View {
    
    @Binding var games: [Games]
    
    var body: some View {
        List {
            ForEach(games, id: \.self) { game in
                Text("\(game.version.name.capitalized) - #\(game.game_index) in national dex")
            }
        }
        .navigationTitle("Games")
        .navigationBarTitleDisplayMode(.inline)
    }
}

#Preview {
    GamesDetails(games: .constant([.preview]))
}
