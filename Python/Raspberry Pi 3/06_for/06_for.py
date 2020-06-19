# title = "06_for"
# made by Lieman at 2020.06.17
#
# description:
#   for example





# main
# while True:
#     base = input("Input base: ")
# 
#     if base.isdecimal():
#         base = int(base)
#         if base >= 2 and base <= 9:
#             break;
#     
#     print("Invalid input!")
# 
# for i in range(1, 10):
#     print("%d * %d = %2d" % (base, i, base * i))

for i in [2, 3, 5]:
    for j in range(1, 10):
        print("%d * %d = %2d" % (i, j, i * j))
    print()
