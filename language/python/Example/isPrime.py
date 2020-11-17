def run():
    number = int(input("Input an integer: "))

    for i in range(2, number // 2 + 1):
        if number % i == 0:
            break
    else:
        print(True)
        return

    print(False)
    return
