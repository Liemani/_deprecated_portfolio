import RPi.GPIO as GPIO
import time

class LED:
    def __init__(self, pin):
        self.pin = pin
        GPIO.setup(pin, GPIO.OUT, initial = GPIO.LOW)

    def on(self):
        GPIO.output(self.pin, GPIO.HIGH)

    def off(self):
        GPIO.output(self.pin, GPIO.LOW)
        
class DCMotor:
    def __init__(self, pPin, nPin, enPin):
        self.pPin = pPin
        self.nPin = nPin
        self.enPin = enPin
        
        GPIO.setup(pPin, GPIO.OUT, initial = GPIO.LOW)
        GPIO.setup(nPin, GPIO.OUT, initial = GPIO.LOW)
        GPIO.setup(enPin, GPIO.OUT, initial = GPIO.LOW)

    def clockWise(self, duration):
        GPIO.output(self.pPin, GPIO.HIGH)
        GPIO.output(self.nPin, GPIO.LOW)
        GPIO.output(self.enPin, GPIO.HIGH)
        time.sleep(duration)
        self.stop()
        
    def counterClockWise(self, duration):
        GPIO.output(self.pPin, GPIO.LOW)
        GPIO.output(self.nPin, GPIO.HIGH)
        GPIO.output(self.enPin, GPIO.HIGH)
        time.sleep(duration)
        self.stop()
        
    def stop(self, duration = 0):
        GPIO.output(self.pPin, GPIO.HIGH)
        GPIO.output(self.nPin, GPIO.HIGH)
        GPIO.output(self.enPin, GPIO.HIGH)
        time.sleep(duration)
