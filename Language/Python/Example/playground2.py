def test16():
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


if __name__ == "__main__":
    test16()
