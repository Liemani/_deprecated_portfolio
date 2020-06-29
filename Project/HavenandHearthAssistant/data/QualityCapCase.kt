package com.havenandhearthassistant.data

enum class QualityCapCase {
    softCap,
    hardCap;

    companion object {
        fun initBy(character: Char): QualityCapCase {
            return if (character == 'h') hardCap else softCap
        }
    }
}