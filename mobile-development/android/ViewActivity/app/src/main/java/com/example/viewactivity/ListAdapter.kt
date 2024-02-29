package com.example.viewactivity

import android.view.LayoutInflater
import android.view.View
import android.view.ViewGroup
import android.widget.ImageView
import android.widget.TextView
import androidx.recyclerview.widget.RecyclerView
import com.bumptech.glide.Glide

class ListAdapter(private val products: List<Product>) : RecyclerView.Adapter<ItemCell>() {
    override fun getItemCount(): Int {
        return products.size
    }

    override fun onCreateViewHolder(parent: ViewGroup, viewType: Int): ItemCell {
        return ItemCell(
            LayoutInflater.from(parent.context).inflate(R.layout.list_item, parent, false)
        )
    }

    override fun onBindViewHolder(holder: ItemCell, position: Int) {
        holder.updateCellWith(products[position])
    }
}

class ItemCell(v: View) : RecyclerView.ViewHolder(v) {

    private val imageView = v.findViewById<ImageView>(R.id.list_item_image)
    private val textView = v.findViewById<TextView>(R.id.list_item_line1)
    private val descView = v.findViewById<TextView>(R.id.list_item_line2)

    fun updateCellWith(value: Product) {
        Glide.with(itemView).load(value.image).into(imageView)
        textView.text = value.name
        descView.text = value.brand
    }
}
