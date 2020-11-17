package com.havenandhearthassistant

class DPScale(mainActivity: MainActivity) {
    val scale = mainActivity.getResources().getDisplayMetrics().density
    fun from(int: Int): Int {
        return (int * scale).toInt()
    }
}
