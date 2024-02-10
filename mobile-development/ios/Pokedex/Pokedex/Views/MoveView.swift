//
//  MoveView.swift
//  Pokedex
//
//  Created by Maxence Bekier on 09/02/2024.
//

import SwiftUI

struct MoveView: View {
    
    let title: String
    let url: String
    @State var type: String?
    @State var currentMove: Move?
    
    var body: some View {
        HStack {
            Text(title)
            Spacer()
            if let currentMove {
                Text(currentMove.type.name.uppercased())
                    .foregroundStyle(Types.color(forTypeName: currentMove.type.name))
            } else {
                ProgressView()
            }
        }
        .onAppear {
            Task {
                guard let url = URL(string: url) else {
                    print("Error with URL")
                    return
                }
                
                let (data, response) = try await URLSession.shared.data(from: url)
                
                guard (response as? HTTPURLResponse)?.statusCode == 200 else {
                    print("Error with request")
                    return
                }
                
                let moveResult = try JSONDecoder().decode(Move.self, from: data)
                currentMove = moveResult
            }
        }
    }
}

#Preview {
    MoveView(title: MoveLink.preview.name, url: MoveLink.preview.url)
}
