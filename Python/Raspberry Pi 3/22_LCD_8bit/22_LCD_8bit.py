# title = "22_LCD_8bit"
# made by Lieman at 2020.06.19
#
# description:
#   LCD example





# import
import RPi.GPIO as GPIO
import time





# class
class LCD:
    def __init__(self, characterPinArray, controlPinArray):
        self.characterPinArray = []
        self.controlPinArray = []
        
        for pin in characterPinArray:
            self.characterPinArray.append(pin)
            GPIO.setup(pin, GPIO.OUT, initial = GPIO.LOW)
        
        self.rsPin = controlPinArray[0]
        self.rwPin = controlPinArray[1]
        self.ePin = controlPinArray[2]
        
        for pin in controlPinArray:
            GPIO.setup(pin, GPIO.OUT, initial = GPIO.LOW)
        
        self.initializeDevice()
    
    def initializeDevice(self):
        # 1
        time.sleep(0.04)
        
        # 2
        self.exportData(0x30)
        time.sleep(0.004)
        
        # 4
        self.exportData(0x30)
        time.sleep(0.0002)
        
        # 6
        self.exportData(0x30)
        time.sleep(0.002)
        
        # 7
        self.exportData(0x38)
        time.sleep(0.002)
        self.exportData(0x08)
        time.sleep(0.002)
        self.exportData(0x01)
        time.sleep(0.002)
        self.exportData(0x04)
        time.sleep(0.002)
    
    def exportData(self, data, duration = 0):
        for i in range(0, 8):
            GPIO.output(self.characterPinArray[i], data >> i & 0x1)
        
#         GPIO.output(self.ePin, GPIO.HIGH)
#         time.sleep(duration)
#         GPIO.output(self.ePin, GPIO.LOW)
    
    def exportCharacter(self, data, duration = 0):
        for i in range(0, 8):
            GPIO.output(self.characterPinArray[i], data >> i & 0x1)
        
#         GPIO.output(self.rsPin, GPIO.HIGH)
#         time.sleep(duration)
#         GPIO.output(self.rsPin, GPIO.LOW)





# main
GPIO.setmode(GPIO.BOARD)

characterPinArray = [21, 22, 23, 24, 31, 33, 35, 37, ]
characterPinArray.reverse()
controlPinArray = [11, 13, 16, ]

lcd = LCD(characterPinArray, controlPinArray)

# 2
lcd.exportCharacter(0x30)
time.sleep(0.002)

# 3
lcd.exportCharacter(0x0E)
time.sleep(0.002)

# 4
lcd.exportCharacter(0x06)
time.sleep(0.002)

# 5
GPIO.output(lcd.rsPin, GPIO.HIGH)
lcd.exportCharacter(0x48)
time.sleep(0.002)

# 6
lcd.exportCharacter(0x49)
time.sleep(0.002)



try:
    while True:
        time.sleep(10000)

except KeyboardInterrupt:
    print("KeyboardInterrupt occured")

finally:
    GPIO.cleanup()
    print("terminated")