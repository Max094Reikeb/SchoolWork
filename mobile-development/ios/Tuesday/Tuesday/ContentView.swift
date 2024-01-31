//
//  ContentView.swift
//  Tuesday
//
//  Created by Maxence Bekier on 30/01/2024.
//

import SwiftUI

struct ContentView: View {
    
    @State var counter = 0
    @State var cursor = 0.5

    var body: some View {
        VStack {
            Text("Counter: \(counter)")
                .font(.largeTitle)
            Button(action: {
                self.counter += 1
            }) {
                Text("Increment")
                    .font(.title)
                    .padding()
                    .background(.blue)
                    .foregroundColor(.white)
                    .cornerRadius(10)
            }
            CursorView(cursor: $cursor)
        }
    }
}

#Preview {
    ContentView()
}
