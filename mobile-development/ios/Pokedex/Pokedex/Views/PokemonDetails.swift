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
    
    init(pokemon: Pokemon) {
        self.currentPokemon = pokemon
        self.urlString = "https://pokeapi.co/api/v2/pokemon/\(pokemon.id)/"
    }
    
    var body: some View {
        ZStack {
            // Color(UIColor.systemBackground).ignoresSafeArea()
            
            VStack {
                if let currentPokemon {
                    ZStack {
                        AsyncImage(url: URL(string: currentPokemon.sprites.front_default))
                            .padding(.top)
                        Circle()
                            .stroke()
                            .frame(width: 100, height: 100)
                            .foregroundStyle(Types.color(forTypeName: currentPokemon.types.first!.type.name))
                    }
                    Text(currentPokemon.name.capitalized)
                        .font(.largeTitle)
                        .bold()
                    
                    Form {
                        Section("More details") {
                            HStack {
                                Text(currentPokemon.types.count > 1 ? "Types" : "Type")
                                Spacer()
                                Text(currentPokemon.types.first!.type.name.capitalized)
                                    .foregroundStyle(Types.color(forTypeName: currentPokemon.types.first!.type.name))
                                if currentPokemon.types.count > 1 {
                                    Spacer().frame(width: 3)
                                    Text("&")
                                    Spacer().frame(width: 3)
                                    Text(currentPokemon.types.last!.type.name.capitalized)
                                        .foregroundStyle(Types.color(forTypeName: currentPokemon.types.last!.type.name))
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
        }
        .task {
            do {
                guard let url = URL(string: self.urlString) else {
                    print("Error with URL")
                    return
                }
                
                if currentPokemon != nil { return }
                
                let (data, response) = try await URLSession.shared.data(from: url)
                
                guard (response as? HTTPURLResponse)?.statusCode == 200 else {
                    print("Error with request")
                    return
                }
                
                let pokemon = try JSONDecoder().decode(Pokemon.self, from: data)
                currentPokemon = pokemon
            } catch {
                print(error.localizedDescription)
            }
        }
    }
}

#Preview {
    PokemonDetails(pokemon: .preview)
}
