import numpy as np


def __mlp(x, w, b):
    y = np.sum(w * x) + b
    if y <= 0:
        return 0
    else:
        return 1


def run():
    def __nand(lhs, rhs):
        return __mlp(np.array([lhs, rhs]), w11, b1)

    def __or(lhs, rhs):
        return __mlp(np.array([lhs, rhs]), w12, b2)

    def __and(lhs, rhs):
        return __mlp(np.array([lhs, rhs]), w2, b3)

    def __xor(lhs, rhs):
        return __and(__nand(lhs, rhs), __or(lhs, rhs))

    w11 = np.array([-2, -2])
    w12 = np.array([2, 2])
    w2 = np.array([1, 1])

    b1 = 3
    b2 = -1
    b3 = -1

    for x1, x2 in [(0, 0), (1, 0), (0, 1), (1, 1)]:
        y = __xor(x1, x2)
        print("Input value: " + str((x1, x2)) + " output value: " + str(y))