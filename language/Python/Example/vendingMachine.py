cost = int(input("Enter cost: "))

count_1000 = int(input("How many 1000 won would you enter: "))
count_500 = int(input("How many 500 won would you enter: "))
count_100 = int(input("How many 100 won would you enter: "))

enteredMoney = 1000 * count_1000 + 500 * count_500 + 100 * count_100
changes = enteredMoney - cost

changes_500, changes = divmod(enteredMoney, 500)
changes_100, changes = divmod(enteredMoney, 100)
changes_10, changes = divmod(enteredMoney, 10)
changes_1, changes = divmod(enteredMoney, 1)

print("500원=",changes_500,"100원=",changes_100,"10원=",changes_10,"1원=",changes_1)
