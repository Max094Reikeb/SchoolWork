package com.example.myapp

fun main() {
    // MARK: Variables
    val test = "Maxence" // val est immuable et de type String
    var name = "Name" // var peut être modifié, et de type String

    // MARK: Nullabilité
    var var1: String = "Max"
    var var2: String?
    // var1 ne peut pas être mis à null
    var2 = null
    // var2.uppercase() ne fonctionne pas car var2 est null
    // Manière 1 :
    if (var2 != null) {
        (var2 as String).uppercase()
    }
    // Manière 2 :
    (var2 as? String)?.uppercase() ?: ""

    // (var2 as? String)!!.uppercase() // Comme var2 est toujours null, cela ne donnera rien

    // L'opérateur Elvis est ?: il est utilisé dans la manière 2

    // MARK: If
    isEven(3)

    // MARK: When
    isVoyelle('e')
    isVoyelle('t')

    // MARK: Boucles
    for (i in 0..100) println(i)
    for (j in 100 downTo 0) println(j)
}

fun isEven(arg: Int): Boolean {
    return arg%2 == 0
}

fun isVoyelle(arg: Char): Boolean {
    return when(arg) {
        'a', 'e', 'i', 'o', 'u', 'y' -> true
        else -> false
    }
}
