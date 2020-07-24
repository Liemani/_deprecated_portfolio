def merge_sort(number_list, predicate):
    length = len(number_list)

    if length == 1:
        return number_list

    result = []

    left_list = merge_sort(number_list[:length // 2], predicate)
    right_list = merge_sort(number_list[length // 2:], predicate)

    while True:
        if len(left_list) == 0 and len(right_list) == 0:
            return result
        elif len(left_list) == 0:
            result.append(right_list.pop(0))
        elif len(right_list) == 0:
            result.append(left_list.pop(0))
        else:
            if predicate(right_list[0], left_list[0]):
                result.append(right_list.pop(0))
            else:
                result.append(left_list.pop(0))


def run():
    number_list = [14, 7, 3, 12, 9, 11, 6, 2]
    print(merge_sort(number_list, lambda x, y: x < y))


if __name__ == "__main__":
    run()
