//
//  SelectNameView.swift
//  ProdigesMap
//
//  Created by Maxence Bekier on 02/02/2024.
//

import SwiftUI

struct SelectNameView: View {
    @Binding var isVisible: Bool
    var body: some View {
        NavigationView {
            VStack {
                Text("Well no")
            }
            .navigationTitle("Modifier votre nom")
            .navigationBarTitleDisplayMode(.large)
            .toolbar {
                ToolbarItem(placement: .primaryAction) {
                    Button("Terminé") {
                        isVisible.toggle()
                    }
                }
            }
        }
        .navigationViewStyle(.stack)
    }
}

#Preview {
    SelectNameView(isVisible: .constant(true))
}
