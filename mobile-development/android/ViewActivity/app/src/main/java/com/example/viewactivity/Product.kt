package com.example.viewactivity

import java.net.URL

class Product(val name: String, val brand: String, val barcode: String, val nutriscore: Nutriscore, val image: String, val quantity: String, val countries: List<String>, val ingredients: List<String>, val allergenes: List<String>, val additifs: List<String>) {

}

enum class Nutriscore {
    A, B, C, D, E
}