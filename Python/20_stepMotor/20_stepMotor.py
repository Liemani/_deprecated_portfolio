# title = "20_stepMotor"
# made by Lieman at 2020.06.18
#
# description:
#   step motor example





# import
import RPi.GPIO as GPIO
import time





# class
class StepMotor:
    def __init__(self, *pinArray):
        self.pinArray = []
        for pin in pinArray:
            self.pinArray.append(pin)
    
    def outputData(self, data):
        for pin in self.pinArray:
            GPIO.output(pin, data >> i & 0x1)





# function
def output




# main
onePhaseOnFullStepTable = [0x1, 0x2, 0x4, 0x8]
twoPhaseOnFullStepTable = []

oneTwoPhaseOnHalfStep = []

GPIO.setmode(GPIO.BOARD)

pinArray = [31, 33, 35, 37, ]
for i in range(0, 4):
    GPIO.setup(pinArray[i], GPIO.OUT, initial = GPIO.LOW)

try:
    while True:
#         for i in range(0, -4, -1):
#             GPIO.output(pinArray[0], GPIO.LOW)
#             GPIO.output(pinArray[1], GPIO.LOW)
#             GPIO.output(pinArray[2], GPIO.LOW)
#             GPIO.output(pinArray[3], GPIO.LOW)
#             
#             GPIO.output(pinArray[i], GPIO.HIGH)
#             time.sleep(0.004)
        for i in range():
            

except KeyboardInterrupt:
    print("KeyboardInterrupt occured")
    pass

finally:
    for i in range(0, 4):
        GPIO.output(pinArray[i], GPIO.HIGH)
    GPIO.cleanup()
    print("terminated")
