# title = "19_LED"
# made by Lieman at 2020.06.17
#
# description:
#   display count number of switch with LED





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

    def turn(self, onOff):
        GPIO.output(self.pin, onOff)
    
    def change(self):
        GPIO.output(self.pin, not GPIO.input(self.pin))

    def sliderChanged(self, dutyCycle):
        self.pwm.ChangeDutyCycle(int(dutyCycle))





# main
GPIO.setmode(GPIO.BOARD)

SW = 13

count = 0

def increaseCount(something):
    global count
    count += 1
    count %= 16

GPIO.setup(SW, GPIO.IN)

ledArray = [LED(37), LED(35), LED(33), LED(31), ]

GPIO.add_event_detect(SW, GPIO.RISING, callback = increaseCount)

try:
    while True:
        for i in range(0, 4):
            tmp = 0
            if ((count >> i) & 0x1) == 1:
                tmp = GPIO.HIGH
            else:
                tmp = GPIO.LOW
            ledArray[i].turn(tmp)

except KeyboardInterrupt:
    print("KeyboardInterrupt occured")
    pass

finally:
    for i in range(0, 4):
        ledArray[i].off
    GPIO.cleanup()
    print("terminated")