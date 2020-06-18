# title = "19_interrupt"
# made by Lieman at 2020.06.18
#
# description:
#   display count number of switch to LED
#   use interrupt when increase count





# import
import RPi.GPIO as GPIO
import time





# class
class LED:
    def __init__(self, pin):
        self.pin = pin
        GPIO.setup(pin, GPIO.OUT, initial = GPIO.LOW)
    
    def startPWM(self):
        self.pwm = GPIO.PWM(self.pin, 100)
        self.pwm.start(0)
    
    def stopPWM(self):
        self.pwm.stop()

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





# function
def displayCount():
    global count
    for i in range(0, 4):
        ledArray[i].turn(count >> i & 0x1)

def changedCount(pin):
    global count
    
    if pin == addSwitch:
        count += 1
    elif pin == subtractSwitch:
        count -= 1
    
    count %= 16
    displayCount()





# main
GPIO.setmode(GPIO.BOARD)

addSwitch = 13
subtractSwitch = 15

count = 0

GPIO.setup(addSwitch, GPIO.IN)
GPIO.setup(subtractSwitch, GPIO.IN)

ledArray = [LED(37), LED(35), LED(33), LED(31), ]

GPIO.add_event_detect(addSwitch, GPIO.RISING, callback = changedCount)
GPIO.add_event_detect(subtractSwitch, GPIO.RISING, callback = changedCount)

try:
    while True:
        time.sleep(10000)

except KeyboardInterrupt:
    print("KeyboardInterrupt occured")
    pass

finally:
    for i in range(0, 4):
        ledArray[i].off
    GPIO.cleanup()
    print("terminated")
