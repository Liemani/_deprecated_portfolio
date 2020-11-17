def get_overlapped_word(word_list):
    from collections import defaultdict

    default_dict = defaultdict(lambda: 0)

    for word in word_list:
        default_dict[word] += 1

    return [word for word, count in default_dict.items() if count > 1]


def get_overlapped_word2(word_list):
    from collections import Counter

    return [word for word, count in Counter(word_list).items() if count > 1]


def run00():
    name = ["Tom", "Jerry", "Mike", "Tom"]
    print(get_overlapped_word(name))

    name2 = ["Tom", "Jerry", "Mike", "Tom", "Mike"]
    print(get_overlapped_word(name2))


def run01():
    name = ["Tom", "Jerry", "Mike", "Tom"]
    print(get_overlapped_word2(name))

    name2 = ["Tom", "Jerry", "Mike", "Tom", "Mike"]
    print(get_overlapped_word2(name2))


if __name__ == "__main__":
    run00()
    run01()
