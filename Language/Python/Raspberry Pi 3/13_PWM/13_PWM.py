# title = "13_PWM"
# made by Lieman at 2020.06.17
#
# description:
#   PWM example





# import
import RPi.GPIO as GPIO
import time





# class
class LED:
    def __init__(self, pin):
        self.pin = pin
        GPIO.setup(pin, GPIO.OUT, initial = GPIO.LOW)
    def off(self):
        GPIO.output(self.pin, GPIO.LOW)





# main
GPIO.setmode(GPIO.BOARD)
ledArray = [LED(11)]
dc = [0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 12, 13, 15, 20, 30, 50, 70, 100]

p = GPIO.PWM(ledArray[0].pin, 100)
p.start(0)

try:
    while True:
        for val in dc:
            p.ChangeDutyCycle(val)
            time.sleep(0.1)
        dc.reverse()
        time.sleep(0.1)

except KeyboardInterrupt:
    print("KeyboardInterrupt occured")
    pass

finally:
    for led in ledArray:
        led.off()
    GPIO.cleanup()
    print("Terminated")
