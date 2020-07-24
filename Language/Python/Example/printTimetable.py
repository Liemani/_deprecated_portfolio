def run():
    print("What time table would you want to display?(2 ~ 9)")
    time = int(input())

    while time != 0:
        print("%d time table" % time)
        for i in range(1, 10):
            print("%d x %d = %d" % (time, i, time * i))

        print("What time table would you want to display?(2 ~ 9)")
        time = int(input())


def run2():
    while True:
        print("What timetable would you want to display?(2 ~ 9)")
        print("Exit: (0)")
        time = int(input())

        if 2 <= time <= 9:
            print("%d timetable" % time)
            for i in range(1, 10):
                print("%d x %d = %d" % (time, i, time * i))
        elif time == 0:
            break
        else:
            print("Invalid number! \n")

    print("Terminating timetable")
