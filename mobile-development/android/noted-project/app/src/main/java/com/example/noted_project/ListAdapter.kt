package com.example.noted_project

import android.view.LayoutInflater
import android.view.View
import android.view.ViewGroup
import android.widget.ImageView
import android.widget.TextView
import androidx.recyclerview.widget.RecyclerView
import com.bumptech.glide.Glide

class ListAdapter(private val series: List<Serie>, private val listener: OnClickListener?) :
    RecyclerView.Adapter<ItemCell>() {
    override fun getItemCount(): Int {
        return series.size
    }

    override fun onCreateViewHolder(parent: ViewGroup, viewType: Int): ItemCell {
        return ItemCell(
            LayoutInflater.from(parent.context).inflate(R.layout.list_item, parent, false)
        )
    }

    override fun onBindViewHolder(holder: ItemCell, position: Int) {
        val serie = series[position]
        holder.updateCellWith(serie)
        holder.itemView.setOnClickListener {
            listener?.onSerieClicked(serie, holder.itemView)
        }
    }
}

interface OnClickListener {
    fun onSerieClicked(serie: Serie, itemView: View)
}

class ItemCell(v: View) : RecyclerView.ViewHolder(v) {

    private val imageView = v.findViewById<ImageView>(R.id.list_item_image)
    private val titleView = v.findViewById<TextView>(R.id.list_item_title)
    private val publisherView = v.findViewById<TextView>(R.id.list_item_publisher)
    private val episodeView = v.findViewById<TextView>(R.id.list_item_episodes)
    private val dateView = v.findViewById<TextView>(R.id.list_item_date)

    fun updateCellWith(value: Serie) {
        Glide.with(itemView).load(value.image.normal).into(imageView)
        titleView.text = value.name
        publisherView.text = value.publisher.name
        episodeView.text = value.episodeCount.toString()
        dateView.text = value.startYear.toString()
    }
}