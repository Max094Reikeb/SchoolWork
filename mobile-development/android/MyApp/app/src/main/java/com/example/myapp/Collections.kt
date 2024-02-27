package com.example.myapp

fun main() {
    // MARK: Sommes
    val list = listOf(1, 4, 7, 9, 8, 7, 2)
    var result = 0
    for (i in list) {
        result += i
    }
    println(result)
    println(list.sum())
}
