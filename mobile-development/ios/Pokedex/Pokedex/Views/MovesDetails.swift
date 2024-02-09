//
//  MovesDetails.swift
//  Pokedex
//
//  Created by Maxence Bekier on 09/02/2024.
//

import SwiftUI

struct MovesDetails: View {
    
    @Binding var moves: [Moves]
    
    var body: some View {
        List {
            ForEach(moves, id: \.self) { move in
                MoveView(title: move.move.name.capitalized, url: move.move.url)
            }
        }
        .navigationTitle("Moves")
        .navigationBarTitleDisplayMode(.inline)
    }
}

#Preview {
    MovesDetails(moves: .constant([.preview]))
}
