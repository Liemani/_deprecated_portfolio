def biggest_number_index(*number_list):
    if len(number_list) == 0:
        return -1

    biggest_number = number_list[0]
    biggest_index = 0

    for index, number in enumerate(number_list[1:]):
        if number > biggest_number:
            biggest_number = number
            biggest_index = index + 1

    return biggest_index


def biggest_number_index2(*number_list):
    biggest_number = max(number_list)
    return number_list.index(biggest_number)


def test26():
    print("Biggest number index:", biggest_number_index(17, 92, 18, 33, 58, 7, 33, 42, 1))


def test27():
    print("Biggest number index:", biggest_number_index2(17, 92, 18, 33, 58, 7, 33, 42, 1))
