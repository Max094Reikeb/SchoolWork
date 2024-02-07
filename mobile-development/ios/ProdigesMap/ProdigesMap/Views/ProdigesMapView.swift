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
    @State var position: MKCoordinateRegion
    
    init() {
        position = MKCoordinateRegion(center: model.center, span: MKCoordinateSpan(latitudeDelta: 0.01, longitudeDelta: 0.01))
    }
    
    var body: some View {
        NavigationView {
            ZStack(alignment: .bottomTrailing) {
                Map(initialPosition: MapCameraPosition.region(position)) {
                    ForEach(model.trackedProdiges) { prodige in
                        Marker(prodige.name, systemImage: "person.circle", coordinate: CLLocationCoordinate2D(latitude: prodige.position.latitude, longitude: prodige.position.longitude))
                    }
                }
                VStack {
                    HStack {
                        if let currentProdige = model.currentProdige {
                            Text(currentProdige.name)
                                .font(.largeTitle)
                                .underline()
                                .bold()
                                .padding(.leading)
                            Spacer()
                        }
                    }
                    Spacer()
                    HStack {
                        Spacer()
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
        .navigationViewStyle(.stack)
        .sheet(isPresented: $newUserPresented ) { LoginView() }
    }
}

#Preview {
    ProdigesMapView()
}
