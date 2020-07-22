def run():
    from random import randint

    number = []
    guess = []

    while len(number) < 3:
        new_number = randint(1, 9)
        for i in number:
            if new_number == i:
                break
        else:
            number.append(new_number)
    else:
        number = list(map(str, number))

    strike = 0
    ball = 0
    while True:
        print(number)
        strike = 0
        ball = 0
        guess.clear()

        for i in range(1, 4):
            guess.append(input("Enter %dth number: " % i))

        for guess_index, i in enumerate(guess):
            for number_index, j in enumerate(number):
                if i == j:
                    if guess_index == number_index:
                        strike += 1
                    else:
                        ball += 1
                    break

        print(guess)
        print("%dS %dB" % (strike, ball))

        if strike == 3:
            break

    print("Congratulation!")
    print("The number is", number)