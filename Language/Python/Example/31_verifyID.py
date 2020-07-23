def verify_id():
    while True:
        resident_id = input("Enter resident id: ")
        if len(resident_id) == 13:
            break
        else:
            print("Invalid Input")

    id_list = list(map(int, resident_id))

    mul_list = [2, 3, 4, 5, 6, 7, 8, 9, 2, 3, 4, 5]

    total = 0
    for i in range(12):
        total += id_list[i] * mul_list[i]

    remainder = total % 11

    confirm_number = 11 - remainder
    del remainder

    if confirm_number == 11:
        confirm_number = 1
    elif confirm_number == 10:
        confirm_number = 0

    if confirm_number == id_list[12]:
        print("Verified!")
    else:
        print("Fail verifying!")
