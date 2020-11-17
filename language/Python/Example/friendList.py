def run():
    cutting_line = "---------------------"

    menu_list = {1: "print friend list",
                 2: "add friend",
                 3: "remove friend",
                 4: "edit friend name",
                 9: "quit"}

    friend_list = []

    while True:
        print(cutting_line)
        for key in menu_list:
            print("%d. %s" % (key, menu_list[key]))
        selection = int(input("select menu: "))

        if selection == 1:
            print("Friend list:")
            print(friend_list)

        elif selection == 2:
            name = input("Enter name to add: ")
            friend_list.append(name)

        elif selection == 3:
            name = input("Enter name to remove: ")
            friend_list.remove(name)

        elif selection == 4:
            name = input("Enter name to search: ")
            fixed_name = input("Enter name to change: ")
            index = friend_list.index(name)
            friend_list[index] = fixed_name

            del fixed_name, index

        elif selection == 9:
            break

        else:
            print("Invalid input! \n")
