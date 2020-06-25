package com.havenandhearthassistant

import android.view.KeyEvent
import androidx.appcompat.widget.AppCompatEditText

class LMTEditText(mainActivity: MainActivity) : AppCompatEditText(mainActivity) {
    override fun onKeyUp(keyCode: Int, event: KeyEvent?): Boolean {
        val mainActivity = context as MainActivity
        return when (keyCode) {
            KeyEvent.KEYCODE_ENTER -> {
                mainActivity.hideKeyboard()
                clearFocus()
                true
            }
            else -> {
                mainActivity.editTextChanged(this)
                super.onKeyUp(keyCode, event)
            }
        }
    }
}