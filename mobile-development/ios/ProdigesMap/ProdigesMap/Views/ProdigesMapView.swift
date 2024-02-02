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
    var body: some View {
        let model = ProdigesModel.shared
        @State var position = MKCoordinateRegion(center: model.center, span: MKCoordinateSpan(latitudeDelta: 0.01, longitudeDelta: 0.01))
        Map(initialPosition: MapCameraPosition.region(position)) {
            UserAnnotation() {
                Text("\(model.name)")
            }
        }
    }
}

#Preview {
    ProdigesMapView()
}
