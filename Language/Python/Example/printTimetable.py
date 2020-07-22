def run():
    print("What time table would you want to display?(2 ~ 9)")
    time = int(input())

    while time != 0:
        print("%d time table" % time)
        for i in range(1, 10):
            print("%d x %d = %d" % (time, i, time * i))

        print("What time table would you want to display?(2 ~ 9)")
        time = int(input())