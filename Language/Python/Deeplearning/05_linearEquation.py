import numpy as np


def get_linear_equation():
    x = [2, 4, 6, 8]
    y = [81, 93, 91, 97]

    data = [[2, 81], [4, 93], [6, 91], [8, 97]]

    mx = np.mean(x)
    my = np.mean(y)

    numerator = sum([(x_val - mx) * (y_val - my) for x_val, y_val in zip(x, y)])
    denominator = sum([(i - mx) ** 2 for i in x])

    a = numerator / denominator
    b = my - (mx * a)
