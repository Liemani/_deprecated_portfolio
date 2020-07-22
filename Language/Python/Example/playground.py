def test00():
    a = input().split()
    del a[-5:]
    print(a)


def test01():
    student_list = ["e hwang", "e e", "1 hyo"]
    print("Current student", student_list)

    new_student = input("Enter the name of new student: ")
    student_list.append(new_student)

    print("sorting")
    student_list.sort()

    for i in range(0, len(student_list)):
        print(i + 1, student_list[i])


def test02():
    weight = int(input("How weight your luggage?"))

    if weight >= 20:
        print("You have to pay 20 dollars.")
    else:
        print("There is no additional pay.")

    print("Thank you.")


def test03():
    score = int(input("Enter your score: "))

    if score >= 140:
        print("You can graduate!")
    else:
        print("You are hard to graduate!")


def test04():
    months = int(input("How long have your baby born? "))

    if 0 <= months <= 1:
        print("Should be vaccinated against tuberculosis.")

    if 0 <= months <= 2:
        print("Should be vaccinated against Hepatitis B.")

    if 2 <= months <= 6:
        print("Should be vaccinated against tetanus.")

    if 2 <= months <= 15:
        print("Should be vaccinated against Pneumococcus.")


def test05():
    string = input("Enter string: ")

    length = len(string)
    if length % 2 == 0:
        print(string[length // 2 - 1], string[length // 2], sep="")
    else:
        print(string[length // 2])


def test06():
    korean = int(input("Korean score"))
    english = int(input("English score"))
    history = int(input("History score"))
    select1 = int(input("Select1 score"))
    select2 = int(input("Select2 score"))

    if korean < 40 or \
            english < 40 or \
            history < 40 or \
            english < 40 or \
            select1 < 40 or \
            select2 < 40:
        print("F")
    else:
        print("P")


def test08():
    quality = input("Enter the quality of apple: ")
    price = int(input("Enter the price of an apple: "))

    if quality == "fresh":
        if price < 1000:
            print("Buy 10 apple")
        else:
            print("Buy 5 apple")
    else:
        print("Don't buy apple.")


def test09():
    total = 0

    for number in range(1, 101):
        if number % 3 == 0:
            total += number

    print(total)


def test10():
    number = int(input("Enter number: "))

    total = 0
    while number != 0:
        number, digit = divmod(number, 10)
        total += digit

    print("total: ", total)


def test11():
    number = input("Enter number: ")

    total = 0
    for digit in number:
        total += int(digit)

    print("total: ", total)


def test12():
    print("If you want to exit, enter negative number")

    total = 0
    count = 0
    score = int(input("Enter score: "))
    while score >= 0:
        total += score
        count += 1
        score = int(input("Enter score: "))

    print("Average:", total / count)


def test13():
    sentence = "I love you"

    reversed_sentence = ""
    for char in sentence:
        reversed_sentence = char + reversed_sentence

    print(reversed_sentence)


def test14():
    number_string = "0123456789"
    int_list = map(lambda x: int(x + x), number_string)
    print(list(int_list))


if __name__ == "__main__":
    test14()
