package com.havenandhearthassistant.data

import com.havenandhearthassistant.MainActivity
import com.havenandhearthassistant.R
import java.io.BufferedReader

class DataController(
    mainActivity: MainActivity
) : ItemGettable {
    val itemMap: MutableMap<Int, Item> = mutableMapOf<Int, Item>()

    init {
        val resIDList = listOf(R.raw.concrete_item_data, R.raw.item_category_data)

        for (resID in resIDList) {
            initByParsingData(mainActivity, resID)
        }
    }

    private fun initByParsingData(mainActivity: MainActivity, resourceId: Int) {
        val inputStream = mainActivity.resources.openRawResource(resourceId)
        val bufferedReader = BufferedReader(inputStream.reader())

        var lineOfString = bufferedReader.readLine()
        while (lineOfString != null) {
            Item.parseFrom(lineOfString, this)
            lineOfString = bufferedReader.readLine()
        }

        bufferedReader.close()
    }

    override fun getItemBy(name: String): Item {
        val itemId = name.hashCode()
        var item = itemMap[itemId]
        if (item == null) {
            item = Item(name)
            itemMap.put(itemId, item)
        }

        return item
    }
}