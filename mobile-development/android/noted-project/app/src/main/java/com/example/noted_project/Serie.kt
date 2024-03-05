package com.example.noted_project

import android.os.Parcelable
import com.google.gson.annotations.SerializedName
import kotlinx.parcelize.Parcelize

@Parcelize
data class Serie(
    val id: Int,
    val name: String,
    val image: Image,
    val publisher: Publisher,
    @SerializedName("count_of_episodes")
    val episodeCount: Int,
    @SerializedName("start_year")
    val startYear: Int,
    @SerializedName("api_detail_url")
    val detailUrl: String
) : Parcelable

@Parcelize
data class Image(
    @SerializedName("super_url")
    val normal: String,
    @SerializedName("original_url")
    val original: String
) : Parcelable

@Parcelize
data class Publisher(
    val id: Int,
    val name: String
) : Parcelable

fun generateFakeSerie() = Serie(
    id = 1,
    name = "Les agents du SHIELD",
    image = Image(
        normal = "https://comicvine.gamespot.com/a/uploads/scale_large/6/67663/6238345-3060875932-35677.jpg",
        original = "https://comicvine.gamespot.com/a/uploads/original/6/67663/6238345-3060875932-35677.jpg"
    ),
    publisher = Publisher(
        id = 31,
        name = "Marvel"
    ),
    episodeCount = 170,
    startYear = 2013,
    detailUrl = "https://comicvine.gamespot.com/api/series/4075-1/"
)
