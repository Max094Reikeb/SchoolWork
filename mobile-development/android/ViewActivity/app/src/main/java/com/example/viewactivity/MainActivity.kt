package com.example.viewactivity

import android.graphics.Typeface
import android.os.Bundle
import android.text.SpannableString
import android.text.style.StyleSpan
import android.widget.ImageView
import android.widget.TextView
import androidx.appcompat.app.AppCompatActivity
import androidx.core.content.ContextCompat
import androidx.recyclerview.widget.LinearLayoutManager
import androidx.recyclerview.widget.RecyclerView
import com.bumptech.glide.Glide

class MainActivity : AppCompatActivity() {
    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.list)
        supportActionBar?.setBackgroundDrawable(
            ContextCompat.getDrawable(
                this,
                R.drawable.gradient
            )
        )

        findViewById<RecyclerView>(R.id.list).apply {
            val content = List(1000) { generateFakeProduct() }

            layoutManager = LinearLayoutManager(this@MainActivity)
            adapter = ListAdapter(content)
        }
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
