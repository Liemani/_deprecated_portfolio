def test00():
    u = [2, 2]
    v = [2, 3]
    z = [3, 5]

    print([sum(row) for row in zip(u, v, z)])


def sum_vector(lhs, rhs):
    return [sum(row) for row in zip(lhs, rhs)]
