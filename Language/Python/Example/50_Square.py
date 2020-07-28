class Square:
    def __init__(self, side):
        self.side = side

    def get_area(self):
        return self.side * self.side


def print_area(square, count):
    for _ in range(count):
        print(square.side, "\t", square.get_area())
        square.side += 1


def run():
    square = Square(10)
    print_area(square, 5)
