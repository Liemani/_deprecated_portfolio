beverages = [{"name": "cider", "cost": 700},
             {"name": "coke", "cost": 800},
             {"name": "water", "cost": 1200}]

for beverage in beverages:
    print(beverage["name"], beverage["cost"], sep="-", end=" ")
print()

money = int(input("Input money: "))

for i in range(3):
    print(i + 1, beverages[i]["name"], sep="-", end=" ")

selection = int(input())

beverage = beverages[selection - 1]

if money >= beverage["cost"]:
    print("Here is a ", beverage["name"], ".", sep="")
    print("And here is your change.", money - beverage["cost"])
else:
    print("You can't buy a ", beverage["name"], ".", sep="")
    print("Here is your money.", money)

del beverages
