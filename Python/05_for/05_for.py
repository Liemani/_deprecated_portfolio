# title = "05_for"
# made by Lieman at 2020.06.17
#
# description:
#   for example





# main
sum = 0

startNumber = int(input("Input start number: "))
endNumber = int(input("Input end number: "))

for i in range(startNumber, endNumber + 1):
    sum += i

print("sum: %d" %sum)

fruit = [1, 2, 3, 4]
