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
            Color(uiColor: UIColor.quaternarySystemFill).ignoresSafeArea()
            
            VStack {
                if let currentPokemon {
                    ZStack {
                        AsyncImage(url: URL(string: currentPokemon.sprites.front_default))
                            .padding(.top)
                        Circle()
                            .stroke()
                            .frame(width: 125, height: 125)
                            .foregroundStyle(Types.color(forTypeName: currentPokemon.types.first!.type.name))
                    }
                    Text(currentPokemon.name.capitalized)
                        .font(.largeTitle)
                        .bold()
                    
                    Form {
                        Section("More details") {
                            HStack {
                                Text("National dex #")
                                Spacer()
                                Text("\(currentPokemon.id)")
                            }
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
                            HStack {
                                Text("Height")
                                Spacer()
                                Text("\(Double(currentPokemon.height) / 10.0, specifier: "%.1f") m")
                            }
                            HStack {
                                Text("Weight")
                                Spacer()
                                Text("\(Double(currentPokemon.weight) / 10, specifier: "%.1f") kg")
                            }
                            HStack {
                                Text("Base experience")
                                Spacer()
                                Text("\(currentPokemon.base_experience)")
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
                            HStack {
                                Text(currentPokemon.abilities.count > 1 ? "Abilities" : "Ability")
                                Spacer()
                                Text(currentPokemon.abilities.map { $0.ability.name.capitalized }.joined(separator: ", "))
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
