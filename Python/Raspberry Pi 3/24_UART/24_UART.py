# title = "24_UART"
# made by Lieman at 2020.06.18
#
# description:
#   UART example





# import
import serial

import RPi.GPIO as GPIO
import time

import tkinter





# class





# main
GPIO.setmode(GPIO.BOARD)

led = 40

GPIO.setup(led, GPIO.OUT, initial = GPIO.LOW)

serial = serial.Serial("/dev/serial0")
serial.baudrate = 57600

try:
    while True:
        data = serial.read(1)
        serial.write(data)
        print(data)
        print(type(data))
        if data == bytes("o", "utf-8"):
            GPIO.output(led, GPIO.HIGH)
        elif data == bytes("x", "utf-8"):
            GPIO.output(led, GPIO.LOW)
    serial.close()
    
except KeyboardInterrupt:
    print("KeyboardInterrupt occured")
    pass

finally:
    GPIO.output(led, GPIO.LOW)
    GPIO.cleanup()
    print("terminated")

