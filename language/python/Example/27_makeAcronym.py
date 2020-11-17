def make_acronym():
    while True:
        print("Enter sentence. Quit(q)")

        word_list = input()

        if word_list == "q":
            break

        word_list = word_list.split(" ")

        for word in word_list:
            print(word[0])

    print("Terminating")
