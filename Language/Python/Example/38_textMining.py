def process_string(string):
    return "".join(filter(str.isalpha, string)).upper()


def text_mining(file_name):
    from collections import defaultdict
    from collections import OrderedDict

    file = open(file_name, "r")

    word_list = [process_string(word)
                 for line in file.readlines()
                 for word in line.split()]

    default_dict = defaultdict(lambda: 0)

    for word in word_list:
        default_dict[word] += 1

    for key, value in OrderedDict(sorted(default_dict.items(), key=lambda t: t[1], reverse=True)).items():
        print("{} {}".format(key, value))

    file.close()


if __name__ == "__main__":
    text_mining("yesterday.txt")
