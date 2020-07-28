class Calculator:
    def sum(self, lhs, rhs):
        print(lhs + rhs)

    def minus(self, lhs, rhs):
        print(lhs - rhs)

    def multiply(self, lhs, rhs):
        print(lhs * rhs)

    def divide(self, lhs, rhs):
        print(lhs / rhs)


def run():
    calc = Calculator()
    calc.sum(10, 5)
    calc.minus(10, 5)
    calc.multiply(10, 5)
    calc.divide(10, 5)
