def test14():
    number = 10

    binary = ""
    while number != 0:
        number, remainder = divmod(number, 2)
        binary = str(remainder) + binary

    print("Binary:", binary)
