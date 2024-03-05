package com.example.noted_project

import com.jakewharton.retrofit2.adapter.kotlin.coroutines.CoroutineCallAdapterFactory
import kotlinx.coroutines.Deferred
import okhttp3.OkHttpClient
import okhttp3.logging.HttpLoggingInterceptor
import retrofit2.Retrofit
import retrofit2.converter.gson.GsonConverterFactory
import retrofit2.http.GET
import retrofit2.http.Header
import retrofit2.http.Query

data class SeriesResult(
    val results: List<Serie>
)

data class SerieResult(
    val results: Serie
)

interface API {

    @GET("series_list")
    fun getList(
        @Query("api_key") apiKey: String,
        @Header("Content-type") contentType: String,
      /*  @Query("format") format: String,
        @Query("sort") sort: String,
        @Query("limit") limit: Int*/
    ): Deferred<SeriesResult>

    // @GET("series/4075-1/")
    // fun getSpecific(): Deferred<SerieResult>
}

object NetworkRequest {

    private val seriesApi = Retrofit.Builder()
        .baseUrl("https://comicvine.gamespot.com/api/")
        .client(OkHttpClient.Builder()
            .addInterceptor(HttpLoggingInterceptor().setLevel(HttpLoggingInterceptor.Level.BODY))
            .build())
        .addConverterFactory(GsonConverterFactory.create())
        .addCallAdapterFactory(CoroutineCallAdapterFactory())
        .build()
        .create(API::class.java)

    suspend fun getList() =
        seriesApi.getList(
            "ac0e4b56140119e1bf5433a18cbd8d63772bac5c",
            "application/json"
         /*   "json",
            "count_of_issue_appearances:desc",
            15*/
        ).await()
}