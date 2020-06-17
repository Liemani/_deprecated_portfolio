from tkinter import *
import RPi.GPIO as GPIO
import time

# object
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

GPIO.setmode(GPIO.BOARD)

SW = [13, 15, 16, 18]

for pin in SW:
    GPIO.setup(pin, GPIO.IN)

ledArray = [LED(31), LED(33), LED(35), LED(37), ]

try:
    while True:
        for i in range(0, 4):
            if GPIO.input(SW[i]) == GPIO.LOW:
                ledArray[i].off()
            else:
                ledArray[i].on()

except KeyboardInterrupt:
    print("KeyboardInterrupt occured")
    pass

finally:
    GPIO.cleanup()
    print("terminated")

