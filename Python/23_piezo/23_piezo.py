# title = "23_piezo"
# made by Lieman at 2020.06.19
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
        GPIO.setup(pin, GPIO.OUT)
        self.pwm = GPIO.PWM(pin, 1)
        self.pwm.start(50)
    
    def changeFrequency(self, frequency):
        self.pwm.ChangeFrequency(int(frequency))
    
    def changeDutyCycle(self, dutyCycle):
        self.pwm.ChangeDutyCycle(int(dutyCycle))





# tkinter
GPIO.setmode(GPIO.BOARD)

piezo = Piezo(29)

window = tkinter.Tk()

frequencySlider = tkinter.Scale(window,
                       label = "frequency",
                       orient = "h",
                       from_ = 1, to_ = 300,
                       command = piezo.changeFrequency)
frequencySlider.pack()

dutyCycleSlider = tkinter.Scale(window,
                       label = "duty cycle",
                       orient = "h",
                       from_ = 0, to_ = 100,
                       command = piezo.changeDutyCycle)
dutyCycleSlider.pack()

window.mainloop()

GPIO.cleanup()
print("terminated")