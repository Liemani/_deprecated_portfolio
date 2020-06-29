# title = "22_LCD_8bit"
# made by Lieman at 2020.06.18
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
#         # 1. wait for more than 40 ms after Vcc rises to 2.7 V
#         time.sleep(0.04)
        
        # 2. 00/0011****
        # 3. wait for more than 4.1 ms
#         self.exportData(0x30, 0.0004)
#         self.exportData(0x38, 0.05)
        
        # 4. 00/0011****
        # 5. wait for more than 100 us
#         self.exportData(0x30, 0.0004)
# #         
# #         # 6. 00/0011****
#         self.exportData(0x30, 0.0004)
# #         
# #         # 7. 00/0011NF**
# #         # 8. 00/00001111
# #         # 9. 00/00000001 clear display
# #         # 10. 00/000001IS
#         self.exportData(0x30, 0.0004)
        self.exportData(0x0D, 0.0004)
        self.exportData(0x01, 0.0004)
        self.exportData(0x06, 0.0004)
    
    def exportData(self, data, duration = 0):
        for i in range(8):
            GPIO.output(self.characterPinArray[i], (data >> i) & 0x1)
        
        GPIO.output(self.ePin, GPIO.HIGH)
        time.sleep(0.000002)
        GPIO.output(self.ePin, GPIO.LOW)
        time.sleep(duration)
    
#     def exportCharacter(self, data, duration = 0):
#         for i in range(8):
#             GPIO.output(self.characterPinArray[i], data >> i & 0x1)
#         
#         GPIO.output(self.rsPin, GPIO.HIGH)
#         time.sleep(duration)
#         GPIO.output(self.rsPin, GPIO.LOW)





# main
GPIO.setmode(GPIO.BOARD)

characterPinArray = [21, 23, 22, 24, 31, 33, 35, 37, ]
controlPinArray = [11, 13, 16, ]

lcd = LCD(characterPinArray, controlPinArray)

# # 2
# lcd.exportData(0x38, 0.02)
# 
# # 3
# lcd.exportData(0x0E, 0.02)
# # time.sleep(0.02)
# 
# # 4
# lcd.exportData(0x06, 0.02)
# 
# lcd.exportData(0x01, 0.002)

# lcd.exportData(0x02, 0.001)

# 5
GPIO.output(lcd.rsPin, GPIO.HIGH)
lcd.exportData(0x48, 0.0004)
lcd.exportData(0x48, 0.0004)

# 6
lcd.exportData(0x49, 0.0004)
lcd.exportData(0x49, 0.0004)
lcd.exportData(0x49, 0.0004)
lcd.exportData(0x49, 0.0004)

lcd.exportData(0x48, 0.0004)



try:
    while True:
        time.sleep(10000)

except KeyboardInterrupt:
    print("KeyboardInterrupt occured")

finally:
    GPIO.cleanup()
    print("terminated")
