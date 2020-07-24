def process_string(string):
    return "".join(filter(str.isalpha, string)).upper()


def count_different_word():
    file = open("proverbs.txt", "r")

    line_list = file.readlines()

    # word_list = []
    #
    # for line in line_list:
    #     word_list.extend(line.split())

    processed_word_list = [process_string(word)
                           for line in line_list
                           for word in line.split()]

    print(len(set(processed_word_list)))

    file.close()


if __name__ == "__main__":
    count_different_word()
