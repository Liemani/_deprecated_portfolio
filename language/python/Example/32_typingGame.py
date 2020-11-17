def typing_game():
    from time import time
    from random import choice

    w = ["cat", "dog", "fox", "monkey", "mouse", "panda", "frog", "snake", "wolf"]

    start_time = time()

    print("Press Enter To Start!")
    input()

    for i in range(5):
        word = choice(w)

        print("Question %d: %s" % (i + 1, word))

        while True:
            type_string = input()

            if type_string == word:
                break

            print("MiSS! type again!")

        print("next \n")

    total_time = time() - start_time

    print("Time: %.2fs" % total_time)
