package com.example.viewactivity

import com.jakewharton.retrofit2.adapter.kotlin.coroutines.CoroutineCallAdapterFactory
import kotlinx.coroutines.Deferred
import retrofit2.Retrofit
import retrofit2.converter.gson.GsonConverterFactory
import retrofit2.http.GET
import retrofit2.http.Query

data class ProductResult(
    val response: ProductResponse
)

data class ProductResponse(
    val pictures: ProductPictures,
    val name: String,
    val brands: List<String>,
    val nutriScore: String,
    val barcode: String,
    val quantity: String,
    val countries: List<String>,
    val ingredients: ProductIngredients,
    val allergens: ProductAllergenes,
    val additives: Map<String, String>
)

data class ProductPictures(
    val product: String
)

data class ProductIngredients(
    val list: List<String>
)

data class ProductAllergenes(
    val list: List<String>
)

interface API {

    @GET("getProduct")
    fun getProductFromBarcode(@Query("barcode") barcode: String): Deferred<ProductResult>
}

object NetworkRequest {

    private val productApi = Retrofit.Builder()
        .baseUrl("https://api.formation-android.fr/v2/")
        .addConverterFactory(GsonConverterFactory.create())
        .addCallAdapterFactory(CoroutineCallAdapterFactory())
        .build()
        .create(API::class.java)

    suspend fun getProductFromBarcode(barcode: String) =
        productApi.getProductFromBarcode(barcode).await()
}
