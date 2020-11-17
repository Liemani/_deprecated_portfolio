def file_handling01():
    with open("yesterday.txt", "r") as file:
        i = 0
        while True:
            line = file.readline()
            if not line:
                break
            print(str(i) + "===" + line.replace("\n", ""))
            i += 1


def file_handling02():
    import re

    with open("yesterday.txt", "r") as file:
        contents = file.read()
#        word_list = contents.split(" ")
        word_list = re.split(" |\n\n|\n", contents)
        line_list = contents.split("\n")

    print("character count: %d" % len(contents))
    print("word count: %d" % len(word_list))
    print("line count: %d" % len(line_list))


def file_handling03():
    file = open("test2.txt", "w", encoding="utf8")
    for i in range(1, 11):
        data = "%dth line.\n" % i
        file.write(data)
    file.close


def file_handling04():
    import os

    if not os.path.isdir("log"):
        os.mkdir("log")

    if not os.path.exists("log/count_log.txt"):
        file = open("log/count_log.txt", "w", encoding="utf8")
        file.write("Start recording\n")
        file.close()

    with open("log/count_log.txt", "a", encoding="utf8") as file:
        import random, datetime
        for i in range(1, 11):
            stamp = str(datetime.datetime.now())
            value = random.random() * 1000000
            log_line = stamp + "\t" + str(value) + "value created" + "\n"
            file.write(log_line)


def file_handling05():
    with open("score.txt", "r") as score_file:
        score_list = list(map(int, score_file.readlines()))

    total = 0
    for score in score_list:
        total += score

    average = total / len(score_list)

    print("Total: %d, Average: %.2f" % (total, average))
