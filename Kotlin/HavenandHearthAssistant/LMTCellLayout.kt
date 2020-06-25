package com.havenandhearthassistant

import android.text.InputType
import android.view.Gravity
import android.view.View
import android.view.ViewGroup
import android.widget.ImageView
import android.widget.LinearLayout
import android.widget.TextView
import com.havenandhearthassistant.data.Item

class LMTCellLayout(
    mainActivity: MainActivity,
    layout: LinearLayout,
    val item: Item
) : LinearLayout(mainActivity) {
    init {
        val dpScale = DPScale(mainActivity)

        // imageView
        var view: View

        var resourceID = resources.getIdentifier(item.imageName, "drawable", mainActivity.getPackageName())
        if (resourceID == 0) {
            val textView = TextView(mainActivity)
            textView.text = item.name
            view = textView
        } else {
            val imageView = ImageView(mainActivity)
            imageView.setImageResource(resourceID)
            view = imageView
        }

        val imageViewLinearLayoutParams = LinearLayout.LayoutParams(
            dpScale.from(48),
            dpScale.from(48)
        )

        addView(view, imageViewLinearLayoutParams)


        // textView
        var textView: TextView

        if (layout.id == R.id.producer) {
            textView = LMTEditText(mainActivity)
        } else {
            textView = TextView(mainActivity)
        }

        val textViewLinearLayoutParams = LinearLayout.LayoutParams(
            ViewGroup.LayoutParams.MATCH_PARENT,
            dpScale.from(48)
        )
        textViewLinearLayoutParams.gravity = Gravity.CENTER
        textViewLinearLayoutParams.setMargins(dpScale.from(8), 0, 0, 0)
        val formattedString = String.format("%.1f", item.quality)
        textView.setText(formattedString)
        textView.hint = "enter quality"
        textView.textSize = dpScale.from(10).toFloat()
        textView.gravity = Gravity.CENTER
        textView.maxLines = 1
        textView.inputType = InputType.TYPE_CLASS_NUMBER

        addView(textView, textViewLinearLayoutParams)
    }
}
