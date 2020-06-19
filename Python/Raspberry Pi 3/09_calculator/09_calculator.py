# title = "09_calculator"
# made by Lieman at 2020.06.17
#
# description:
#   calculator example





# main
# global variable
sum = 0
operators = ["+", "-", "*", "/"]

# function
def plus(number1, number2):
    return number1 + number2

def calc(lhs, rhs, op):
    if op == "+":
        return lhs + rhs
    elif op == "-":
        return lhs + rhs
    elif op == "*":
        return lhs * rhs
    elif op == "/":
        return lhs / rhs

# main
while True:
    operator = input("Input operator: ")
    
    if operator in operators:
        break
    else:
        print("Invalid input")

while True:
    lhs = input("Input lhs: ")
    
    if lhs.isdecimal():
        lhs = int(lhs)
        break
    else:
        print("Invalid input")

while True:
    rhs = input("Input rhs: ")
    
    if rhs.isdecimal():
        if operator == "/" and rhs == "0":
            print("You can't devide by 0")
        else:
            rhs = int(rhs)
            break
    else:
        print("Invalid input")

result = calc(lhs, rhs, operator)
print(result)
