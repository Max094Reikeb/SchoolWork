package com.example.myapp

import java.lang.Exception

enum class NetworkStateEnum(state: String) {
    INITIAL("404"), IN_PROGRESS("404"), SUCCESS("404"), ERROR("404")
}

sealed class NetworkStateClass() {}
data object InitialState : NetworkStateClass() {}
data object InProgressState : NetworkStateClass() {}
class SuccessState(state: String) : NetworkStateClass() {}
class ErrorState(error: Exception) : NetworkStateClass() {}
