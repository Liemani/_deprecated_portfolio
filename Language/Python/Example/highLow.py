def run():
    from random import randint

    bottom = 1
    top = 100

    number = randint(bottom, top)

    print("Guess the number. (%d ~ %d)" % (bottom, top))
    guess = int(input())
    while guess != number:
        if guess > number:
            print("Too high.")
        elif guess < number:
            print("Too low.")

        guess = int(input())

    print("Congratulation!")
