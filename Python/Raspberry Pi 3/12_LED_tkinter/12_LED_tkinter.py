# title = "12_LED_tkinter"
# made by Lieman at 2020.06.17
#
# description:
#   LED, tkinter example





# import
import RPi.GPIO as GPIO
import time

import tkinter





# function
def func0():
    GPIO.output(LED0, not GPIO.input(LED0))

def func1():
    GPIO.output(LED1, not GPIO.input(LED1))





# main
GPIO.setmode(GPIO.BOARD)
LED0 = 11
LED1 = 12

GPIO.setup(LED0, GPIO.OUT, initial = GPIO.LOW)
GPIO.setup(LED1, GPIO.OUT, initial = GPIO.LOW)

window = tkinter.Tk()
window.title("LED Controller")
window.config(bg = "#00FF00")
window.geometry("300x300")

label = tkinter.Label(window, text = "press button")
label.pack()

button = tkinter.Button(window,
                        text = "LED0",
                        command = func0,
                        height = 10,
                        width = 10)
button.pack()

button = tkinter.Button(window,
                        text = "LED1",
                        command = func1)
button.pack()

window.mainloop()

GPIO.cleanup()
