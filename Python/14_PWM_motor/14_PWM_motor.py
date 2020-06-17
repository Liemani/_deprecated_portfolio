# title = "14_PWM_motor"
# made by Lieman at 2020.06.17
#
# description:
#   PWM dc motor example





# import
import RPi.GPIO as GPIO
import time





# class
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





# main
try:
    GPIO.setmode(GPIO.BOARD)
    motor = DCMotor(11, 13, 15)
    
    while True:
        motor.clockWise(1)
        motor.stop(0.5)
        motor.counterClockWise(1)
        motor.stop(0.5)

except KeyboardInterrupt:
    print("KeyboardInterrupt occured")
    pass

finally:
    motor.stop(0)
    GPIO.cleanup()
    print("Terminated")
