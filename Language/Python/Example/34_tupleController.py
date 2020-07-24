def tuple_controller():
    print("Tuple Controller ver.1")
    print("Enter elements, separator is space")
    main_tuple = tuple(input().split())

    while True:
        print("Enter command")
        command = input("Quit [q]\tSlicing [s]\tCount [c]\tFind [i]: ")

        if command == "q":
            print("terminating")
            break
        elif command == "s":
            start = int(input("From: "))
            end = int(input("To: "))
            print(main_tuple[start:end])
        elif command == "c":
            search_value = input("Enter value to search: ")
            print(main_tuple.count(search_value))
        elif command == "i":
            search_value = input("Enter value to search: ")
            print(search_value in main_tuple)
        else:
            print("Undefined command! \n")


if __name__ == "__main__":
    tuple_controller()
