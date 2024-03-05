package com.example.viewactivity

import android.graphics.Typeface
import android.os.Bundle
import android.text.SpannableString
import android.text.Spanned
import android.text.style.StyleSpan
import android.text.style.UnderlineSpan
import android.transition.TransitionInflater
import android.view.LayoutInflater
import android.view.View
import android.view.ViewGroup
import android.widget.ImageView
import android.widget.TextView
import androidx.fragment.app.Fragment
import com.bumptech.glide.Glide
import kotlinx.coroutines.Dispatchers
import kotlinx.coroutines.GlobalScope
import kotlinx.coroutines.launch
import kotlinx.coroutines.withContext

class DetailFragment : Fragment() {

    override fun onCreateView(
        inflater: LayoutInflater,
        container: ViewGroup?,
        savedInstanceState: Bundle?
    ): View? {
        return inflater.inflate(
            R.layout.details,
            container,
            false
        )
    }

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        val transition =
            TransitionInflater.from(requireContext()).inflateTransition(android.R.transition.move)
        sharedElementEnterTransition = transition
        sharedElementReturnTransition = transition
    }

    override fun onViewCreated(view: View, savedInstanceState: Bundle?) {
        super.onViewCreated(view, savedInstanceState)

        GlobalScope.launch(Dispatchers.Default) {
            val response = NetworkRequest.getProductFromBarcode("5000159484695")

            withContext(Dispatchers.Main) {
                val allergenes = response.response.allergens.list.joinToString()
                val additifs = response.response.additives.keys.toList().joinToString()

                Glide.with(this@DetailFragment).load(response.response.pictures.product)
                    .into(view.findViewById(R.id.image))
                view.findViewById<TextView>(R.id.title).setText(response.response.name)
                view.findViewById<TextView>(R.id.brand)
                    .setText(response.response.brands.joinToString())
                view.findViewById<ImageView>(R.id.nutriscore).setImageResource(
                    when (response.response.nutriScore) {
                        "A" -> R.drawable.nutriscore_a
                        "B" -> R.drawable.nutriscore_b
                        "C" -> R.drawable.nutriscore_c
                        "D" -> R.drawable.nutriscore_d
                        else -> R.drawable.nutriscore_e
                    }
                )
                view.findViewById<TextView>(R.id.barcode)
                    .applyBold("Code barres: ${response.response.barcode}")
                view.findViewById<TextView>(R.id.quantity)
                    .applyBold("Quantité: ${response.response.quantity}")
                view.findViewById<TextView>(R.id.sold)
                    .applyBold("Vendu en: ${response.response.countries.joinToString()}")
                view.findViewById<TextView>(R.id.ingredients)
                    .applyUnderline("Ingrédients: ${response.response.ingredients.list.joinToString()}")
                view.findViewById<TextView>(R.id.allergenes)
                    .applyBold("Substances allergènes: ${if (allergenes == "") "Aucune" else allergenes}")
                view.findViewById<TextView>(R.id.additifs)
                    .applyBold("Additifs: ${if (additifs == "") "Aucun" else additifs}")
            }
        }

        val product = DetailFragmentArgs.fromBundle(requireArguments()).product

        // Glide.with(this).load(product.image).into(view.findViewById(R.id.image))
        // view.findViewById<TextView>(R.id.title).setText(product.name)
        // view.findViewById<TextView>(R.id.brand).setText(product.brand)
        // view.findViewById<ImageView>(R.id.nutriscore).setImageResource(
        //     when (product.nutriscore) {
        //         Nutriscore.A -> R.drawable.nutriscore_a
        //         Nutriscore.B -> R.drawable.nutriscore_b
        //         Nutriscore.C -> R.drawable.nutriscore_c
        //         Nutriscore.D -> R.drawable.nutriscore_d
        //         else -> R.drawable.nutriscore_e
        //     }
        // )
        // view.findViewById<TextView>(R.id.barcode).applyBold("Code barres: ${product.barcode}")
        // view.findViewById<TextView>(R.id.quantity).applyBold("Quantité: ${product.quantity}")
        // view.findViewById<TextView>(R.id.sold)
        // .applyBold("Vendu en: ${product.countries.joinToString()}")
        // view.findViewById<TextView>(R.id.ingredients)
        // .applyBold("Ingrédients: ${product.ingredients.joinToString()}")
        // view.findViewById<TextView>(R.id.allergenes)
        // .applyBold("Substances allergènes: ${product.allergenes.joinToString()}")
        // view.findViewById<TextView>(R.id.additifs)
        // .applyBold("Additifs: ${product.additifs.joinToString()}")
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

fun TextView.applyUnderline(originalText: String) {
    val pattern = "_([^_]+)_".toRegex()
    val modifiedText = StringBuffer()
    var adjustment = 0

    pattern.findAll(originalText).fold(originalText) { acc, matchResult ->
        val start = matchResult.range.first - adjustment
        val end = matchResult.range.last - adjustment - 1

        adjustment += 2

        modifiedText.append(acc.substring(modifiedText.length, start))
        modifiedText.append(matchResult.groupValues[1])

        acc.substring(0, start) + matchResult.groupValues[1] + acc.substring(end + 2)
    }

    val spannable = SpannableString(modifiedText.toString())
    adjustment = 0

    pattern.findAll(originalText).forEach { matchResult ->
        val start = matchResult.range.first - adjustment
        val end = matchResult.range.last - adjustment - 1
        adjustment += 2

        spannable.setSpan(
            UnderlineSpan(),
            start,
            end,
            Spanned.SPAN_EXCLUSIVE_EXCLUSIVE
        )
        spannable.setSpan(
            StyleSpan(Typeface.BOLD),
            start,
            end,
            0
        )
        setText(spannable)
    }
    spannable.setSpan(
        StyleSpan(Typeface.BOLD),
        0,
        originalText.indexOf(':') + 1,
        0
    )
    setText(spannable)
}
