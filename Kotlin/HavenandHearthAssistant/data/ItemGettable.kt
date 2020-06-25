package com.havenandhearthassistant.data

interface ItemGettable {
    fun getItemBy(name: String): Item
}