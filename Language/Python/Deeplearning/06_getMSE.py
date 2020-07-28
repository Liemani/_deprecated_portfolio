import numpy as np


class Point:
    def __init__(self, x, y):
        self.x = x
        self.y = y


def y_val_for_x_in_linear_equation(x, a_b):
    return a_b[0] * x + a_b[1]


def mse_of_linear(data, theory_a_b):
    return np.mean([(theory_a_b[0] * point.x + theory_a_b[1] - point.y) ** 2
                    for point in data])


def test04():
    data = [Point(2, 81),
            Point(4, 93),
            Point(6, 91),
            Point(8, 97)]

    theory_a_b = [3, 76]

    x_list = [point.x for point in data]
    y_list = [point.y for point in data]

    mse = mse_of_linear(data, theory_a_b)

    print(mse)
