//
//  ContentView.swift
//  Surface
//
//  Created by Maxence Bekier on 31/01/2024.
//

import SwiftUI

struct ContentView: View {
    
    @State var cursorHeight = 1.0
    @State var cursorWidth = 1.0
    
    var body: some View {
        VStack {
            Text("Height: \(cursorHeight)")
            Slider(value: $cursorHeight, in: 0...100, step: 0.1)
            Spacer().frame(height: 30)
            Text("Width: \(cursorWidth)")
            Slider(value: $cursorWidth, in: 0...100, step: 0.1)
            Spacer().frame(height: 50)
            Text("The surface is: \(cursorWidth * cursorHeight)")
                .font(.title)
        }
        .padding()
    }
}

#Preview {
    ContentView()
}
