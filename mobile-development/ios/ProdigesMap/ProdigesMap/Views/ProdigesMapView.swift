//
//  ProdigesMapView.swift
//  ProdigesMap
//
//  Created by Maxence Bekier on 31/01/2024.
//

import CoreLocation
import MapKit
import SwiftUI

struct ProdigesMapView: View {
    
    let model = ProdigesModel.shared
    @State var newUserPresented = false
    @State var deconnectUser = false
    @State var position: MKCoordinateRegion
    
    init() {
        position = MKCoordinateRegion(center: model.center, span: MKCoordinateSpan(latitudeDelta: 0.01, longitudeDelta: 0.01))
    }
    
    var body: some View {
        NavigationView {
            ZStack(alignment: .bottomTrailing) {
                Map(initialPosition: MapCameraPosition.region(position)) {
                    if model.currentId == nil || !model.trackedProdiges.contains(where: { $0 == model.currentProdige }) {
                        UserAnnotation()
                    }
                    ForEach(model.trackedProdiges) { prodige in
                        Marker(prodige.name, systemImage: "person.circle", coordinate: CLLocationCoordinate2D(latitude: prodige.position.latitude, longitude: prodige.position.longitude))
                    }
                }
                VStack {
                    Spacer()
                    HStack {
                        Spacer()
                        if let currentProdige = model.currentProdige {
                            Button(action: {
                                deconnectUser.toggle()
                            }) {
                                Text(currentProdige.name)
                                    .font(.largeTitle)
                                    .underline()
                                    .bold()
                                    .padding(.trailing)
                            }
                        } else {
                            Button(action: {
                                newUserPresented.toggle()
                            }) {
                                Image(systemName: "plus.circle.fill")
                                    .resizable()
                                    .aspectRatio(contentMode: .fill)
                                    .frame(width: 60, height: 60)
                                    .foregroundColor(.blue)
                                    .background(Color.white)
                                    .clipShape(Circle())
                                    .padding(.trailing)
                                    .padding(.top)
                            }
                        }
                    }
                }
            }
        }
        .navigationViewStyle(.stack)
        .sheet(isPresented: $newUserPresented ) { LoginView() }
        .alert(
            "Deconnexion !",
            isPresented: $deconnectUser,
            actions: {
                Button("Oui") {
                    model.updateProdige(id: model.currentId!, values: ["tracked": false])
                    model.currentId = nil
                    deconnectUser.toggle()
                }
                Button("Non") {
                    deconnectUser.toggle()
                }
            },
            message: {
                Text("Voulez-vous vous déconnecter de votre compte ? Si oui, vous devrez vous reconnecter !")
            }
        )
    }
}

#Preview {
    ProdigesMapView()
}
