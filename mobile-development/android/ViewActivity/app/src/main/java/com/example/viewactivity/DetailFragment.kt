package com.example.viewactivity

import android.graphics.Typeface
import android.os.Bundle
import android.text.SpannableString
import android.text.style.StyleSpan
import android.transition.TransitionInflater
import android.view.LayoutInflater
import android.view.View
import android.view.ViewGroup
import android.widget.ImageView
import android.widget.TextView
import androidx.fragment.app.Fragment
import com.bumptech.glide.Glide

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

        val product = DetailFragmentArgs.fromBundle(requireArguments()).product

        Glide.with(this).load(product.image).into(view.findViewById(R.id.image))
        view.findViewById<TextView>(R.id.title).setText(product.name)
        view.findViewById<TextView>(R.id.brand).setText(product.brand)
        view.findViewById<ImageView>(R.id.nutriscore).setImageResource(
            when (product.nutriscore) {
                Nutriscore.A -> R.drawable.nutriscore_a
                Nutriscore.B -> R.drawable.nutriscore_b
                Nutriscore.C -> R.drawable.nutriscore_c
                Nutriscore.D -> R.drawable.nutriscore_d
                else -> R.drawable.nutriscore_e
            }
        )
        view.findViewById<TextView>(R.id.barcode).applyBold("Code barres: ${product.barcode}")
        view.findViewById<TextView>(R.id.quantity).applyBold("Quantité: ${product.quantity}")
        view.findViewById<TextView>(R.id.sold)
            .applyBold("Vendu en: ${product.countries.joinToString()}")
        view.findViewById<TextView>(R.id.ingredients)
            .applyBold("Ingrédients: ${product.ingredients.joinToString()}")
        view.findViewById<TextView>(R.id.allergenes)
            .applyBold("Substances allergènes: ${product.allergenes.joinToString()}")
        view.findViewById<TextView>(R.id.additifs)
            .applyBold("Additifs: ${product.additifs.joinToString()}")
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
