def book_manager():
    from collections import defaultdict

    book_list = [{"name": "a", "borrowed": False},
                 {"name": "b", "borrowed": False},
                 {"name": "c", "borrowed": False},
                 {"name": "d", "borrowed": False},
                 {"name": "e", "borrowed": False},
                 {"name": "f", "borrowed": False},
                 {"name": "g", "borrowed": False},
                 {"name": "h", "borrowed": False},
                 {"name": "i", "borrowed": False},
                 {"name": "j", "borrowed": False}]

    book_borrow_list = defaultdict(lambda: [])

    while True:
        name = input("Enter user name: ")

        if name == "q":
            break

        while True:
            number = input("Enter book code: ")

            if number == "q":
                break

            number = int(number)

            if not (1 <= number <= len(book_list)):
                print("Invalid number!")
                continue
            elif book_list[number - 1]["borrowed"]:
                print("Borrowed state.")
            else:
                book_borrow_list[name].append(book_list[number - 1]["name"])
                book_list[number - 1]["borrowed"] = True

            if len(book_borrow_list[name]) == 3:
                break

    print(dict(book_borrow_list))


class Book:
    def __init__(self, name, borrowed):
        self.name = name
        self.borrowed = borrowed


def book_manager2():
    from collections import defaultdict

    book_list = [Book("a", False),
                 Book("b", False),
                 Book("c", False),
                 Book("d", False),
                 Book("e", False),
                 Book("f", False),
                 Book("g", False),
                 Book("h", False),
                 Book("i", False),
                 Book("j", False)]

    book_borrow_list = defaultdict(lambda: [])

    while True:
        name = input("Enter user name: ")

        if name == "q":
            break

        while True:
            number = input("Enter book code: ")

            if number == "q":
                break

            number = int(number)

            if not (1 <= number <= len(book_list)):
                print("Invalid number!")
                continue
            elif book_list[number - 1].borrowed:
                print("Borrowed state.")
            else:
                book_borrow_list[name].append(book_list[number - 1].name)
                book_list[number - 1].borrowed = True

            if len(book_borrow_list[name]) == 3:
                break

    print(dict(book_borrow_list))


if __name__ == "__main__":
    book_manager2()
