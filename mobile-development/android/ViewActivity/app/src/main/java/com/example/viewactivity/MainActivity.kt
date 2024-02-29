package com.example.viewactivity

import android.graphics.Typeface
import android.os.Bundle
import android.text.SpannableString
import android.text.style.StyleSpan
import android.widget.ImageView
import android.widget.TextView
import androidx.appcompat.app.AppCompatActivity
import androidx.core.content.ContextCompat
import com.bumptech.glide.Glide

class MainActivity : AppCompatActivity() {
    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.details)
        supportActionBar?.setBackgroundDrawable(
            ContextCompat.getDrawable(
                this,
                R.drawable.gradient
            )
        )

        val product = Product(
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
        fillDetails(product)
    }

    private fun fillDetails(product: Product) {
        Glide.with(this).load(product.image).into(findViewById(R.id.image))
        findViewById<TextView>(R.id.title).setText(product.name)
        findViewById<TextView>(R.id.brand).setText(product.brand)
        findViewById<ImageView>(R.id.nutriscore).setImageResource(
            when (product.nutriscore) {
                Nutriscore.A -> R.drawable.nutriscore_a
                Nutriscore.B -> R.drawable.nutriscore_b
                Nutriscore.C -> R.drawable.nutriscore_c
                Nutriscore.D -> R.drawable.nutriscore_d
                else -> R.drawable.nutriscore_e
            }
        )
        findViewById<TextView>(R.id.barcode).applyBold("Code barres: ${product.barcode}")
        findViewById<TextView>(R.id.quantity).applyBold("Quantité: ${product.quantity}")
        findViewById<TextView>(R.id.sold).applyBold("Vendu en: ${product.countries.joinToString()}")
        findViewById<TextView>(R.id.ingredients).applyBold("Ingrédients: ${product.ingredients.joinToString()}")
        findViewById<TextView>(R.id.allergenes).applyBold("Substances allergènes: ${product.allergenes.joinToString()}")
        findViewById<TextView>(R.id.additifs).applyBold("Additifs: ${product.additifs.joinToString()}")
    }
}

fun TextView.applyBold(text: String) {
    val spannable = SpannableString(text)
    spannable.setSpan(
        StyleSpan(Typeface.BOLD),
        0,
        text.indexOf(':') + 1,
        0
    )
    setText(spannable)
}
