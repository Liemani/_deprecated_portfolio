def print_word_count():
    f = open("yesterday.txt", "r")
    yesterday_lyric = f.readlines()

    count = 0
    for line in yesterday_lyric:
        count += line.upper().count("YESTERDAY")

    print("Number of a Word 'Yesterday': ", count)

    f.close()
