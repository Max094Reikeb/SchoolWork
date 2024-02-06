//
//  LoginView.swift
//  ProdigesMap
//
//  Created by Maxence Bekier on 06/02/2024.
//

import SwiftUI

struct LoginView: View {

    let model = ProdigesModel.shared
    @Environment(\.dismiss) var dismiss
    @State private var name = ""
    @State private var password = ""

    var body: some View {
        NavigationView {
            VStack {
                TextField("Nom", text: $name)
                    .padding()
                    .textFieldStyle(RoundedBorderTextFieldStyle())
                SecureField("Mot de passe", text: $password)
                    .padding()
                    .textFieldStyle(RoundedBorderTextFieldStyle())
                
                Button("Se connecter") {
                    let namedProdige = model.prodiges.first(where: { $0.name == name })
                    switch namedProdige {
                    case .none:
                        // Register
                        break
                    case .some(let foundProdige):
                        if foundProdige.password == password {
                            // Login because it's good
                        } else {
                            // Bad password
                        }
                        break
                    }
                }
                .padding()
                .foregroundColor(.white)
                .background(Color.blue)
                .cornerRadius(10)
            }
            .navigationTitle("Connectez-vous")
            .navigationBarTitleDisplayMode(.large)
            .toolbar {
                ToolbarItem(placement: .primaryAction) {
                    Button("Annuler") {
                        dismiss()
                    }
                }
            }
        }
        .navigationViewStyle(.stack)
    }
}

#Preview {
    LoginView()
}
