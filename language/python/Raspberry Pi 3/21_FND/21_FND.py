# title = "21_FND"
# made by Lieman at 2020.06.18
#
# description:
#   FND example





# import
import RPi.GPIO as GPIO
import time





# class
class FND:
    def __init__(self, *pinArray):
        self.pinArray = []
        
        for pin in pinArray:
            self.pinArray.append(pin)
            GPIO.setup(pin, GPIO.OUT, initial = GPIO.LOW)
    
    def display(self, fndData):
        for i in range(0, 8):
            GPIO.output(self.pinArray[i], fndData >> i & 0x1)





# function




# main
GPIO.setmode(GPIO.BOARD)

fndDigitDataArray = [0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07, 0x7F, 0x6F, ]
pinArray = [21, 22, 23, 24, 31, 33, 35, 37, ]
fnd = FND(*pinArray)
try:
    
    while True:
        for i in range(0, len(fndDigitDataArray)):
            fnd.display(fndDigitDataArray[i])
            time.sleep(1)

except KeyboardInterrupt:
    print("KeyboardInterrupt occured")
    pass

finally:
    for pin in fnd.pinArray:
        GPIO.output(pin, GPIO.LOW)
    GPIO.cleanup()
    print("terminated")