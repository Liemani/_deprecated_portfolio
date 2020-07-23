def modify_string():
    while True:
        data = input("Enter Data: ")

        if data == 1:
            break

        data_list = data.split()
        del data

        if len(data_list) != 3:
            print("\nInvalid input!")
            continue

        data_list[0] = "".join(filter(lambda x: x.isalpha(), data_list[0])).upper()
        data_list[1] = "".join(filter(lambda x: x.isdecimal(), data_list[1]))
        data_list[2] = "".join(filter(lambda x: x.isalnum(), data_list[2])).capitalize()

        print(data_list, "\n")
