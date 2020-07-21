import math

print("This is quadratic equation solution calculator! (ax^2 + bx + c = 0)")

aValue = int(input("a value: "))
bValue = int(input("b value: "))
cValue = int(input("c value: "))

inRoot = bValue * bValue - 4 * aValue * cValue

if inRoot < 0:
    print("This quadratic equation has no solution!")
    exit()
elif inRoot == 0:
    print("This quadratic equation has only one solution!")

    numerator = str(-bValue)
    denominator = str(2 * aValue)
else:
    numerator = str(-bValue) + " ± " + str(math.sqrt(inRoot))
    denominator = str(2 * aValue)

    print("The solution of quadratic equation '" + str(aValue) + "x^2 + " + str(bValue) + "x + " + str(cValue) + " = 0' is")

print(numerator)
print("-" * len(numerator))

spaceCount = (len(numerator) - len(denominator)) // 2 + 1

print(" " * spaceCount, denominator)

print("out of if")
