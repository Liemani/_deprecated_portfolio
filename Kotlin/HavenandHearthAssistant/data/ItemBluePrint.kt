package com.havenandhearthassistant.data

class ItemBluePrint(
    val calculationCase: CalculationCase,
    val itemRatioMap: MutableMap<Item, Int>,
    var qualityCap: QualityCap? = null
)