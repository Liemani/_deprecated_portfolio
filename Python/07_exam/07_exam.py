# count = 1
# sum = 0
# 
# while count < 11:
#     sum += count
#     count += 1
# 
# print("Sum from 1 to 10: %d" % sum)

number1 = None
number2 = None

while True:
    while True:
        number1 = input("Input first number: ")
        if number1.isdecimal():
            number1 = int(number1)
            break
        print("Invalid input!")
        
    while True:
        number2 = input("Input second number: ")
        if number2.isdecimal():
            number2 = int(number2)
            break
        print("Invalid input!")
    
    if number1 == 0 or number2 == 0:
        break
    
    print("%d + %d = %d" % (number1, number2, number1 + number2))
    
print("0 has input")
print("Terminating program")
