# title = "02_exam"
# made by Lieman at 2020.06.17
#
# description:
#   simple tkinter example





# import
#from tkinter import *
import tkinter





# function
def mouseClick(event):
    global x1, y1
    x1 = event.x
    y1 = event.y

def mouseDrop(event):
    global x1, y1, x2, y2
    x2 = event.x
    y2 = event.y
    canvas.create_line(x1, y1, x2, y2, width = 5, fill = "red")





# main
window = None
canvas = None
x1, y1, x2, y2 = None, None, None, None

window = Tk()
window.title("paint like program")

canvas = Canvas(window, height = 300, width = 300)
canvas.bind("<Button-1>", mouseClick)
canvas.bind("<ButtonRelease-1>", mouseDrop)
canvas.pack()

window.mainloop()
