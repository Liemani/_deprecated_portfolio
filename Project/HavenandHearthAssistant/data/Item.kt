package com.havenandhearthassistant.data

import kotlin.math.sqrt

class Item(
    name: String
) {
    val name = name
    val id: Int = name.hashCode()
    val influencingItemList: MutableList<Item> = mutableListOf()

    var quality: Float = 10F
    var bluePrint: ItemBluePrint? = null
    var includedItemList: MutableList<Item>? = null

    val isConcreteItem: Boolean
        get() = includedItemList == null

    val isItemCategory: Boolean
        get() = includedItemList != null

    val qualityInfluenced: Boolean
        get() = bluePrint != null

    val qualityInfluences: Boolean
        get() = !influencingItemList.isEmpty()

    val imageName: String
        get() {
            // not elegance,, need to modify
            val nameList = name.split(" ")
            var resultString = StringBuilder(nameList[0])

            for (index in 1..nameList.lastIndex) {
                resultString.append("_")
                resultString.append(nameList[index])
            }

            return resultString.toString()
        }

    companion object {
        fun parseFrom(lineOfString: String, itemGetter: ItemGettable) {
            // make item by name
            val dataList: List<String> = lineOfString.split("  ")

            val name = dataList[0]
            val itemBluePrintData = dataList.elementAtOrNull(1)
            val qualityCapData = dataList.elementAtOrNull(2)

            val item = itemGetter.getItemBy(name)

            if (itemBluePrintData == null) return


            // make includedItemList (if category)
            if (itemBluePrintData[0] == 'c') {
                val includedItemDataList = qualityCapData!!.split(",")

                item.includedItemList = mutableListOf()

                for (index in 0..includedItemDataList.lastIndex) {
                    val includedItemName = includedItemDataList[index]
                    val includedItem = itemGetter.getItemBy(includedItemName)
                    includedItem.influencingItemList.add(item)

                    item.includedItemList!!.add(includedItem)
                }

                return
            }


            // make itemBluePrint
            val itemBluePrintList = itemBluePrintData.split(",")

            val calculationCase = CalculationCase.initBy(itemBluePrintList[0][0])

            item.bluePrint = ItemBluePrint(calculationCase, mutableMapOf())

            for (index in 1..itemBluePrintList.lastIndex step 2) {
                val bluePrintItemName = itemBluePrintList[index]
                val bluePrintItem = itemGetter.getItemBy(bluePrintItemName)
                bluePrintItem.influencingItemList.add(item)
                val bluePrintItemWeight = itemBluePrintList[index + 1].toInt()

                item.bluePrint!!.itemRatioMap.put(bluePrintItem, bluePrintItemWeight)
            }

            if (qualityCapData == null) return


            // make cap
            val qualityCapDataList = qualityCapData.split(",")

            val qualityCapCase = QualityCapCase.initBy(qualityCapDataList[0][0])

            item.bluePrint!!.qualityCap = QualityCap(qualityCapCase, mutableMapOf())

            for (index in 1..qualityCapDataList.lastIndex step 2) {
                val qualityCapItemName = qualityCapDataList[index]
                val qualityCapItem = itemGetter.getItemBy(qualityCapItemName)
                qualityCapItem.influencingItemList.add(item)
                val qualityCapItemWeight = qualityCapDataList[index + 1].toInt()

                val itemRatioMap = item.bluePrint!!.qualityCap!!.itemRatioMap
                itemRatioMap.put(qualityCapItem, qualityCapItemWeight)
            }
        }
    }
}