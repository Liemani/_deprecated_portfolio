def print_character_indices(string, finding_character):
    index_list = []
    for index, character in enumerate(string.upper()):
        if character == finding_character:
            index_list.append(index)

    count = len(index_list)

    for index in range(count):
        print("%d/%d: %d" % (index, count, index_list[index] + 1))


def test32():
    print_character_indices("FINISHED FILES ARE THE RESULT OF YEARS OF SCIENTIFIC STUDY COMBINED WITH THE EXPERIENCE OF YEARS.", "F")
