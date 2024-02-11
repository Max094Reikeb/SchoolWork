//
//  ContentView.swift
//  Pokedex
//
//  Created by Maxence Bekier on 08/02/2024.
//

import SwiftUI

struct ContentView: View {
    
    let model = ApiModel.shared
    
    var body: some View {
        NavigationView {
            List {
                ForEach(model.pokemonLinks, id: \.self) { pokemonLink in
                    NavigationLink {
                        PokemonDetails(urlString: pokemonLink.url)
                    } label: {
                        HStack {
                            Image("pokeball")
                                .resizable()
                                .frame(width: 30, height: 30)
                            Text(pokemonLink.name.capitalized)
                        }
                    }
                }
            }
            .navigationTitle("Pokedex")
        }
    }
}

#Preview {
    ContentView()
}
