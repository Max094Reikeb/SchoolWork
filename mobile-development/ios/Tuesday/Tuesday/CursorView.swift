//
//  CursorView.swift
//  Tuesday
//
//  Created by Maxence Bekier on 31/01/2024.
//

import SwiftUI

struct CursorView: View {
    
    @Binding var cursor: Double
    
    var body: some View {
        VStack {
            Text("Slider: \(cursor)")
                .font(.title)
            Slider(value: $cursor)
        }
        .padding()
    }
}

#Preview {
    CursorView(cursor: .constant(0.5))
}
