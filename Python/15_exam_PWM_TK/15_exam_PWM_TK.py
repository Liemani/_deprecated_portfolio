import tkinter

import RPi.GPIO as GPIO
import time

class LED:
    def __init__(self, pin):
        self.pin = pin
        GPIO.setup(pin, GPIO.OUT, initial = GPIO.LOW)
    
    def turnPWMOn(self):
        self.pwm = GPIO.PWM(self.pin, 100)
        self.pwm.start(0)

    def on(self):
        GPIO.output(self.pin, GPIO.HIGH)

    def off(self):
        GPIO.output(self.pin, GPIO.LOW)
    
    def change(self):
        GPIO.output(self.pin, not GPIO.input(self.pin))

    def sliderChanged(self, dutyCycle):
        self.pwm.ChangeDutyCycle(int(dutyCycle))

# main
GPIO.setmode(GPIO.BOARD)
led0 = LED(11)
led1 = LED(13)

led0.turnPWMOn()
led1.turnPWMOn()

window = tkinter.Tk()
window.title("LED Controller")

slider = tkinter.Scale(window, label = "LED0",
                       orient = 'h',
                       from_ = 0,
                       to_ = 100,
                       command = led0.sliderChanged)
slider.pack(side = 'left')

slider = tkinter.Scale(window, label = "LED1",
                       orient = 'h',
                       from_ = 0,
                       to_ = 100,
                       command = led1.sliderChanged)
slider.pack(side = 'left')

window.mainloop()

GPIO.cleanup()
print("Terminated")
