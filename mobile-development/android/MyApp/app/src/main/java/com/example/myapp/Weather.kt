package com.example.myapp

open class Weather(val temp: Float, val location: String) {
    constructor(weather: Weather) : this(temp = weather.temp, location = weather.location)

    companion object {
        private const val FREEZE_TEMP = 0f
    }

    override fun toString(): String {
        return "Température de $location : $temp"
    }

    fun isCold(): Boolean {
        return temp < FREEZE_TEMP
    }

    open fun isHot(): Boolean {
        return temp > 25
    }
}

class LocalWeather(temp: Float, location: String) : Weather(temp = temp, location = location) {
    constructor(localWeather: LocalWeather) : this(
        temp = localWeather.temp,
        location = localWeather.location
    )

    override fun isHot(): Boolean {
        return temp > 32
    }
}
