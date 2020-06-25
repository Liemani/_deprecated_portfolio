package com.havenandhearthassistant

import android.app.Activity
import androidx.appcompat.app.AppCompatActivity
import android.os.Bundle
import android.view.KeyEvent
import android.view.View
import android.view.ViewGroup.LayoutParams.MATCH_PARENT
import android.view.ViewGroup.LayoutParams.WRAP_CONTENT
import android.view.inputmethod.InputMethodManager
import android.widget.*
import androidx.core.view.get
import com.havenandhearthassistant.data.*
import com.google.android.gms.ads.*
import java.io.BufferedReader
import kotlin.math.sqrt

class MainActivity : AppCompatActivity() {
    lateinit var adView: AdView
    lateinit var dataController: DataController

    lateinit var producerItemViewMap: MutableMap<LMTEditText, Item>
    lateinit var productItemViewMap: MutableMap<Item, TextView>

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_main)

        // set ad
        MobileAds.initialize(this) {}
        adView = findViewById(R.id.adView)
        val adRequest = AdRequest.Builder().build()
        adView.loadAd(adRequest)

        // init model
        dataController = DataController(this)
        producerItemViewMap = mutableMapOf()
        productItemViewMap = mutableMapOf()
        loadQualityData(dataController.itemMap)

        // init view
        initView()
    }

    fun initView() {
        val producerLayout: LinearLayout = findViewById(R.id.producer)
        val productLayout: LinearLayout = findViewById(R.id.product)

        val producerItemListRes = R.raw.producer_item_list
        val productItemListRes = R.raw.product_item_list

        val producerItemList = makeStringList(producerItemListRes)
        val productItemList = makeStringList(productItemListRes)

        for (item in producerItemList) {
            val lmtEditText = addCellLayout(producerLayout, item) as LMTEditText
            producerItemViewMap.put(lmtEditText, item)
        }

        for (item in productItemList) {
            val textView = addCellLayout(productLayout, item)
            productItemViewMap.put(item, textView)
        }

        for (item in productItemViewMap.keys) {
            displayQuality(item)
        }
    }

    fun makeStringList(res: Int): MutableList<Item> {
        val resultList = mutableListOf<Item>()

        val inputStream = resources.openRawResource(res)
        val bufferedReader = BufferedReader(inputStream.reader())

        var itemName = bufferedReader.readLine()
        while (itemName != null) {
            val item = dataController.itemMap.get(itemName.hashCode())
            if (item == null) {
                println("[error: producer_item_list has wrong item.]")
                continue
            }

            resultList.add(item)
            itemName = bufferedReader.readLine()
        }

        bufferedReader.close()

        return resultList
    }

    fun addCellLayout(layout: LinearLayout, item: Item): TextView {
        val dpScale = DPScale(this)

        var linearLayout: LinearLayout

        if (layout.id == R.id.producer) {
            linearLayout = LMTCellLayout(this, layout, item)
        } else {
            linearLayout = LMTCellLayout(this, layout, item)
        }

        val linearLayoutLinearLayoutParams = LinearLayout.LayoutParams(
            MATCH_PARENT,
            WRAP_CONTENT
        )
        linearLayoutLinearLayoutParams.setMargins(0, dpScale.from(8), 0, 0)

        layout.addView(linearLayout, linearLayoutLinearLayoutParams)

        val textView = linearLayout.get(1) as TextView

        return textView
    }

    fun displayQuality(influencedItem: Item) {
        val productItemTextView = productItemViewMap.get(influencedItem)

        val predictedQuality = predictQuality(influencedItem)
        val formattedString = String.format("%.1f", predictedQuality)

        productItemTextView!!.text = formattedString
    }

    fun predictQuality(influencedItem: Item): Float {
        var predictedQuality: Float

        if (influencedItem.isItemCategory) {
            predictedQuality = influencedItem.includedItemList!!.map {
                if (producerItemViewMap.values.contains(it)) {
                    it.quality
                } else {
                    predictQuality(it)
                }
            }.max()!!

            return predictedQuality
        }

        when (influencedItem.bluePrint!!.calculationCase) {
            CalculationCase.average -> {
                var sum: Float = 0F
                var divisor: Int = 0

                for (pair in influencedItem.bluePrint!!.itemRatioMap) {
                    val influencingItem = pair.key

                    var influencingItemPredictedQuality = 0F
                    if (producerItemViewMap.values.contains(influencingItem)) {
                        influencingItemPredictedQuality = influencingItem.quality
                    } else {
                        influencingItemPredictedQuality = predictQuality(influencingItem)
                    }
                    sum += influencingItemPredictedQuality * pair.value
                    divisor += pair.value
                }

                predictedQuality = sum / divisor
            }
            CalculationCase.squreRoot -> {
                var multiplication: Float = 1F

                for (pair in influencedItem.bluePrint!!.itemRatioMap) {
                    val influencingItem = pair.key

                    var influencingItemPredictedQuality = 0F
                    if (producerItemViewMap.values.contains(influencingItem)) {
                        influencingItemPredictedQuality = pair.key.quality
                    } else {
                        influencingItemPredictedQuality = predictQuality(influencingItem)
                    }
                    multiplication *= influencingItemPredictedQuality * pair.value
                }

                predictedQuality = sqrt(multiplication)
            }
        }

        val qualityCap = influencedItem.bluePrint!!.qualityCap
        if (qualityCap != null) {
            var qualityCapAverage = 0F

            var sum: Float = 0F
            var divisor: Int = 0

            for (pair in qualityCap.itemRatioMap) {
                val influencingItem = pair.key

                var influencingItemPredictedQuality = 0F
                if (producerItemViewMap.values.contains(influencingItem)) {
                    influencingItemPredictedQuality = pair.key.quality
                } else {
                    influencingItemPredictedQuality = predictQuality(influencingItem)
                }
                sum += influencingItemPredictedQuality * pair.value
                divisor += pair.value
            }

            qualityCapAverage = sum / divisor

            when (qualityCap.qualityCapCase) {
                QualityCapCase.softCap -> {
                    if (predictedQuality > qualityCapAverage) {
                        predictedQuality = (qualityCapAverage + influencedItem.quality) / 2
                    }
                }
                QualityCapCase.hardCap -> {
                    if (predictedQuality > qualityCapAverage) {
                        predictedQuality = qualityCapAverage
                    }
                }
            }
        }

        return predictedQuality
    }


    fun editTextChanged(sender: LMTEditText) {
        val changedItem = producerItemViewMap.get(sender)
        val qualityText = sender.text.toString().toFloatOrNull()

        if (qualityText != null && qualityText != 0F) {
            changedItem!!.quality = qualityText
            influenceQuality(changedItem)
        }
    }

    fun influenceQuality(item: Item) {
        for (influencedItem in item.influencingItemList) {
            if (productItemViewMap.get(influencedItem) == null) {
                influenceQuality(influencedItem)
            } else {
                displayQuality(influencedItem)
            }
        }
    }


    fun loadQualityData(itemMap: MutableMap<Int, Item>) {
        val sharedPreferences = getSharedPreferences("quality", MODE_PRIVATE)

        for (item in itemMap.values) {
            item.quality = sharedPreferences.getFloat(item.name, 10F)
        }
    }

    fun saveQualityData(itemMap: MutableMap<Int, Item>) {
        val sharedPreferences = getSharedPreferences("quality", MODE_PRIVATE)
        val sharedPreferencesEditor = sharedPreferences.edit()

        for (producerItem in producerItemViewMap.values) {
            sharedPreferencesEditor.putFloat(producerItem.name, producerItem.quality)
        }

        sharedPreferencesEditor.commit()
    }

    fun hideKeyboard() {
        val imm = getSystemService(Activity.INPUT_METHOD_SERVICE) as InputMethodManager
        var view = getCurrentFocus()
        if (view == null) view = View(this)
        imm.hideSoftInputFromWindow(view.getWindowToken(), 0)
    }

    override fun onKeyUp(keyCode: Int, event: KeyEvent?): Boolean {
        println("[###key up function occered!!###]")
        return super.onKeyUp(keyCode, event)
    }

    public override fun onPause() {
        saveQualityData(dataController.itemMap)
        adView.pause()
        super.onPause()
    }

    public override fun onResume() {
        super.onResume()
        adView.resume()
    }

    public override fun onDestroy() {
        adView.destroy()
        super.onDestroy()
    }
}

fun MutableMap<Item, Int>.itemRatioAverage(): Float {
    var sum: Float = 0F
    var divisor: Int = 0

    for (pair in this) {
        sum += pair.key.quality * pair.value
        divisor += pair.value
    }
    return sum / divisor
}