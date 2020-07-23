def get_index(number_list, finding_number):
    for index, number in enumerate(number_list):
        if number == finding_number:
            return index

    return -1


def test28():
    number_list = [17, 92, 18, 33, 58, 5, 33, 42]
    print(get_index(number_list, 500))
