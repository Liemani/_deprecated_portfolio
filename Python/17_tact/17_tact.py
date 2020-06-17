# title = "17_tact"
# made by Lieman at 2020.06.17
#
# description:
#   tact switch example





# import
import RPi.GPIO as GPIO
import time





# class
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

SW0 = 7
GPIO.setup(SW0, GPIO.IN)

led = LED(11)

try:
    while True:
        key_in = GPIO.input(SW0)
        if key_in == GPIO.LOW:
            led.off()
        else:
            led.on()

except KeyboardInterrupt:
    print("KeyboardInterrupt occured")
    pass

finally:
    GPIO.cleanup()
    print("terminated")
