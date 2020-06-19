# title = "10_function"
# made by Lieman at 2020.06.17
#
# description:
#   function example





# function
def para_func(*para):
    sum = 0
    for num in para:
        sum += num
    return sum





# main
result = para_func(10, 20, 30)
print("result: %d" % result)
