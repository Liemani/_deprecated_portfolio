def error_handling01():
    data = {"abc": 1, "def": 2, "ghi": 3, "jkl": 4}

    while True:
        name = input("Enter name: ")
        try:
            print(data[name])
        except KeyError:
            print("I don\'t know that name.")


def error_handling02():
    import datetime
    country_list = ["Korea", "Russia", "Vietnam", "China"]

    while True:
        name = input("Enter country name: ")

        if name == "q":
            break

        try:
            country_list.index(name)
        except ValueError:
            print("{} is not in list! <Recording log>".format(name))
            with open("log.txt", "a") as log_file:
                now = str(datetime.datetime.now())
                log_file.write(now + ": {} is not in list!\n".format(name))
