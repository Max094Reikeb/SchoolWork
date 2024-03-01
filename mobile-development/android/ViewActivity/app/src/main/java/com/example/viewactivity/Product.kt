package com.example.viewactivity

import android.os.Parcelable
import kotlinx.parcelize.Parcelize

@Parcelize
data class Product(
    val name: String,
    val brand: String,
    val barcode: String,
    val nutriscore: Nutriscore,
    val image: String,
    val quantity: String,
    val countries: List<String>,
    val ingredients: List<String>,
    val allergenes: List<String>,
    val additifs: List<String>
) : Parcelable

enum class Nutriscore {
    A, B, C, D, E
}

fun generateFakeProduct() = Product(
    name = "Petits pois et carottes",
    brand = "Cassegrain",
    barcode = "394736288273648",
    nutriscore = Nutriscore.B,
    image = "https://images.unsplash.com/photo-1482049016688-2d3e1b311543?ixlib=rb-1.2.1&q=80&fm=jpg&crop=entropy&cs=tinysrgb&dl=joseph-gonzalez-fdlZBWIP0aM-unsplash.jpg",
    quantity = "400g (280g net égoutté)",
    countries = listOf("France", "Japon", "Suisse"),
    ingredients = listOf(
        "Petits pois 66%",
        "eau",
        "garniture 2,8% (salade oignon, grelot)",
        "sucre",
        "sel",
        "arôme naturel"
    ),
    allergenes = listOf("Aucune"),
    additifs = listOf("Aucun")
)
