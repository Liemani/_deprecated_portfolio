until = int(input("Enter max fahrenheit (from 0): "))
interval = int(input("Enter the interval: "))


for fahrenheit in range(0, until + 1, interval):
    celsius = (fahrenheit - 32) * 5 / 9
    celsius = round(celsius, 2)
    print(fahrenheit, "->", celsius)
