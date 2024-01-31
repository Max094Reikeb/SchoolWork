// import UIKit

let i = 2
let d = 3.14
var greeting = "Hello" + " playground \(i)"
print(greeting)

greeting = ""

func f(_ j: Int) -> Int {
    return 2*j
}

f(3)

let a = [4, 8, 3]
let t = (4, "8", 3)
let (t1, t2, t3) = t

enum Feutre {
    case noir
    case vert
    case rouge
}

let crayon = Feutre.rouge

enum OptionalInt {
    case some(Int)
    case none
}

let oi = OptionalInt.some(7)
let noi = OptionalInt.none

switch oi {
case .some(let i): print("Int \(i)")
case .none: print("none")
}

var opti: Int?
opti = .none

switch opti {
case .some(let i): print(i)
case .none: print("Nothing")
}

if let i = opti { print(i) } else { print("Nothing") }

print(opti != nil ? print(opti!) : print("Nothing"))
