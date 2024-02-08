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
        NavigationSplitView {
            List {
                ForEach(model.pokemonLinks, id: \.self) { pokemonLink in
                    NavigationLink {
                        PokemonDetails(urlString: pokemonLink.url)
                    } label: {
                        Text(pokemonLink.name)
                    }
                }
            }
            .navigationTitle("Pokedex")
        } detail: {
            Text("")
        }
    }
}

#Preview {
    ContentView()
}
