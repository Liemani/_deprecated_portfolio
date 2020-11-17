# title = "23_piezo"
# made by Lieman at 2020.06.19
#
# description:
#   piezo example





# import
import RPi.GPIO as GPIO
import time

import tkinter





# class
class Ultrasonic:
    def __init__(self, triggerPin, echoPin):
        self.triggerPin = triggerPin
        self.echoPin = echoPin
        
        self.startTime = 0
        
        GPIO.setup(triggerPin, GPIO.OUT)
        GPIO.setup(echoPin, GPIO.IN)
    
    def trigger(self):
        GPIO.output(self.triggerPin, GPIO.HIGH)
        time.sleep(0.00001)
        GPIO.output(self.triggerPin, GPIO.LOW)
    
    def echoChanged(self, pin):
        if GPIO.input(pin) == GPIO.HIGH:
            self.startTime = time.time()
        else:
            interval = time.time() - self.startTime
            distance = interval * 340000 / 2
            print(str(round(distance, 2)) + "mm")





# main
GPIO.setmode(GPIO.BOARD)

ultrasonic = Ultrasonic(16, 18)

GPIO.add_event_detect(ultrasonic.echoPin, GPIO.BOTH, callback = ultrasonic.echoChanged)

# tkinter
window = tkinter.Tk()

triggerButton = tkinter.Button(window,
                               text = "Trigger",
                               command = ultrasonic.trigger)
triggerButton.pack()

window.mainloop()

GPIO.cleanup()
print("terminated")