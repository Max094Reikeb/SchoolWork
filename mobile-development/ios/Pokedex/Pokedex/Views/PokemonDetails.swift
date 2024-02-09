//
//  PokemonDetails.swift
//  Pokedex
//
//  Created by Maxence Bekier on 08/02/2024.
//

import SwiftUI

struct PokemonDetails: View {
    
    var urlString: String
    @State var currentPokemon: Pokemon?
    
    init(urlString: String) {
        self.urlString = urlString
    }
    
    var body: some View {
        VStack {
            if let currentPokemon {
                AsyncImage(url: URL(string: currentPokemon.sprites.front_default))
                    .padding(.top)
                Text(currentPokemon.name)
                    .font(.largeTitle)
                    .bold()
                
                List {
                    Section("More details") {
                        HStack {
                            Text("Type(s)")
                            Spacer()
                            Text(currentPokemon.types.first!.type.name)
                            if currentPokemon.types.first! != currentPokemon.types.last! {
                                Text("& \(currentPokemon.types.last!.type.name)")
                            }
                        }
                        NavigationLink {
                            GamesDetails(games: .constant(currentPokemon.game_indices))
                        } label: {
                            Text("Games")
                        }
                        NavigationLink {
                            MovesDetails(moves: .constant(currentPokemon.moves))
                        } label: {
                            Text("Moves")
                        }
                    }
                }
                
                Spacer()
            } else {
                ProgressView()
            }
        }
        .onAppear {
            Task {
                guard let url = URL(string: self.urlString) else {
                    print("Error with URL")
                    return
                }
                
                let (data, response) = try await URLSession.shared.data(from: url)
                
                guard (response as? HTTPURLResponse)?.statusCode == 200 else {
                    print("Error with request")
                    return
                }
                
                let pokemon = try JSONDecoder().decode(Pokemon.self, from: data)
                currentPokemon = pokemon
            }
        }
    }
}

#Preview {
    PokemonDetails(urlString: PokemonLink.preview.url)
}
