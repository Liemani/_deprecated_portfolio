# title = "03_quiz"
# made by Lieman at 2020.06.17
#
# description:
#   simple print example





# main
while True:
    base = input("Input base(2/8/10/16): ")
    if base.isdecimal:
        base = int(base)
        break
    else:
        print("Wrong input!\n")

while True:
    number = input("Input number of that base: ")
    break
#     if number.isdecimal:
#         number = int(number)
#     elif base == 16 && number.isalnum:
        
print("base: {0, d}, number: {1, s}".format(base, int(number, base)))
