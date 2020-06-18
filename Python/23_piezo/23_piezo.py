# title = "23_piezo"
# made by Lieman at 2020.06.18
#
# description:
#   piezo example





# import
import RPi.GPIO as GPIO
import time

import tkinter





# class
class Piezo:
    def __init__(self, pin):
        self.pin = pin
        self.pwm = GPIO.PWM(pin, 1)
        self.pwm.start(50)
    
    def changeFrequency(self, frequency):
        self.pwm.ChangeFrequency(frequency)
    
    def changeDutyCycle(self, dutyCycle):
        self.pwm.ChangeDutyCycle(dutyCycle)





# tkinter
GPIO.setmode(GPIO.BOARD)

piezo = Piezo(29)

window = tkinter.TK()

frequencySlider = tkinter.Scale(window,
                       label = "frequency",
                       orient = "h",
                       from_ = 0, to_ = 100,
                       command = piezo.changeFrequency)
frequencySlider.pack(fill = X)

dutyCycleSlider = tkinter.Scale(window,
                       label = "duty cycle",
                       orient = "h",
                       from_ = 0, to_ = 100,
                       command = piezo.changeDutyCycle)
dutyCycleSlider.pack(fill = X)

window.mainloop()

GPIO.cleanup()
print("terminated")
