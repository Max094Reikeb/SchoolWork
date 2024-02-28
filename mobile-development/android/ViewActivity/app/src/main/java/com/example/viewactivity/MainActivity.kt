package com.example.viewactivity

import android.graphics.Typeface
import android.os.Bundle
import android.text.SpannableString
import android.text.style.StyleSpan
import android.widget.TextView
import androidx.appcompat.app.AppCompatActivity
import androidx.core.content.ContextCompat

class MainActivity : AppCompatActivity() {
    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.detail)
        supportActionBar?.setBackgroundDrawable(
            ContextCompat.getDrawable(
                this,
                R.drawable.gradient
            )
        )

        val textView = findViewById<TextView>(R.id.barcode)
        val spannable = SpannableString(textView.text)
        spannable.setSpan(
            StyleSpan(Typeface.BOLD),
            0,
            textView.text.indexOf(':', 1),
            0
        )
        textView.setText(spannable)
    }
}
