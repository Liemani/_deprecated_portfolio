package com.havenandhearthassistant.data

enum class CalculationCase {
    average,
    squreRoot;

    companion object {
        fun initBy(character: Char): CalculationCase {
            return if (character == 's') squreRoot else average
        }
    }
}