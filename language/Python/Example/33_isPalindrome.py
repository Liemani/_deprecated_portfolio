def palindrome(string):
    string_list = list(map(str.upper, filter(lambda c: c.isalpha(), string)))

    for _ in range(len(string_list) // 2):
        if string_list.pop(0) != string_list.pop():
            return False

    return True


def run():
    print(palindrome("Madam, I'm Adam."))
    print(palindrome("Madam, I'm mAdam."))


if __name__ == "__main__":
    run()
