# title = "11_LED"
# made by Lieman at 2020.06.17
#
# description:
#   LED example





import RPi.GPIO as GPIO
import time

GPIO.setmode(GPIO.BCM)
LED0 = 17
LED1 = 18

# LED0_BCM = 17
# LED1_BCM = 18

GPIO.setup(LED0, GPIO.OUT, initial = GPIO.LOW)
GPIO.setup(LED1, GPIO.OUT, initial = GPIO.LOW)

try:
    while True:
        GPIO.output(LED0, GPIO.HIGH)
        GPIO.output(LED1, GPIO.HIGH)
        time.sleep(0.5)
        
        GPIO.output(LED0, GPIO.LOW)
        GPIO.output(LED1, GPIO.LOW)
        time.sleep(0.5)

except KeyboardInterrupt:
    print("KeyboardInterrupt occured")
    pass

finally:
    GPIO.output(LED0, GPIO.LOW)
    GPIO.output(LED1, GPIO.LOW)
    GPIO.cleanup()
    print("Terminated")

