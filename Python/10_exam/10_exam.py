def para_func(*para):
    print(type(para))
    result = 0
    for num in para:
        result = result + num
    return result

result = 0

result = para_func(10, 20, 30)
print("result: %d" % result)
