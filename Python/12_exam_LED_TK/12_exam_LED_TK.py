import RPi.GPIO as GPIO
import tkinter
import time

GPIO.setmode(GPIO.BOARD)
LED0 = 11
LED1 = 12

GPIO.setup(LED0, GPIO.OUT, initial = GPIO.LOW)
GPIO.setup(LED1, GPIO.OUT, initial = GPIO.LOW)

def func0():
    GPIO.output(LED0, not GPIO.input(LED0))

def func1():
    GPIO.output(LED1, not GPIO.input(LED1))

root = tkinter.Tk()
root.title("LED Controller")
root.config(bg = "#00FF00")
root.geometry("300x300")

label = tkinter.Label(root, text = "press button")
label.pack()
button = tkinter.Button(root,
                        text = "LED0",
                        command = func0,
                        height = 10,
                        width = 10)
button.pack()

button = tkinter.Button(root,
                        text = "LED1",
                        command = func1)
button.pack()

root.mainloop()

GPIO.cleanup()
