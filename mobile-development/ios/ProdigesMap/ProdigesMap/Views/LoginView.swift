//
//  LoginView.swift
//  ProdigesMap
//
//  Created by Maxence Bekier on 06/02/2024.
//

import CoreLocation
import Firebase
import Foundation
import SwiftUI

struct LoginView: View {
    
    let model = ProdigesModel.shared
    @Environment(\.dismiss) var dismiss
    @State private var badName = false
    @State private var badPassword = false
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
                    let namedProdige = model.prodiges.first { $0.name == name }
                    switch namedProdige {
                    case .none:
                        badName.toggle()
                    case .some(let foundProdige):
                        if foundProdige.password == password {
                            model.currentId = nil
                            model.currentId = foundProdige.id!
                            dismiss()
                        } else {
                            badPassword.toggle()
                        }
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
            .alert(
                "Nom introuvable...",
                isPresented: $badName,
                actions: {
                    Button("Oui") {
                        Task {
                            await registerNewProdige()
                        }
                        dismiss()
                    }
                    Button("Non") {
                        badName.toggle()
                    }
                },
                message: {
                    Text("Le nom que vous avez entré n'a pas été trouvé. Souhaitez-vous créer un nouvel identifiant ?")
                }
            )
            .alert(
                "Mauvais mot de passe !",
                isPresented: $badPassword,
                actions: {
                    Button("Ok") {
                        badPassword.toggle()
                    }
                },
                message: {
                    Text("Le mot de passe que vous avez entré n'est pas bon ! Veuillez réessayer...")
                }
            )
        }
        .navigationViewStyle(.stack)
    }
    
    func registerNewProdige() async {
        let position = GeoPoint(latitude: 0, longitude: 0)
        do {
            model.currentId = nil
            let ref = try await ProdigesModel.shared.prodigesCollection.addDocument(data: [
                "name": name,
                "password": password,
                "position": position,
                "tracked": false
            ])
            print("Document added with ID: \(ref.documentID)")
            model.currentId = ref.documentID
        } catch {
            print("Error adding document: \(error.localizedDescription)")
        }
        badName.toggle()
    }
}

#Preview {
    LoginView()
}
