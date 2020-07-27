def transpose(args):
    return [row for row in zip(*args)]


def sum_matrix(lhs, rhs):
    return [[row[0] + row[1] for row in zip(*row_vector_list)] for row_vector_list in zip(lhs, rhs)]


def test00():
    a = [[3, 6], [4, 5]]
    b = [[5, 8], [6, 7]]

    print(sum_matrix(a, b))


def is_equal_matrix(lhs, rhs):
    return all([row[0] == row[1] for t in zip(lhs, rhs) for row in zip(*t)])


def test01():
    a = [[1, 1], [1, 1]]
    b = [[1, 1], [1, 2]]

    print(is_equal_matrix(a, b))


def multiplication_matrix(lhs, rhs):
    return [[sum(lhs_value * rhs_value for lhs_value, rhs_value in zip(lhs_row, rhs_column))
             for rhs_column in zip(*rhs)]
            for lhs_row in lhs]


def test02():
    a = [[1, 2, 3], [4, 5, 6]]
    b = [[7, 8], [9, 10], [11, 12]]

    print(multiplication_matrix(a, b))


def test03():
    a = [[1, 1, 2], [2, 1, 1]]
    b = [[1, 1], [2, 1], [1, 3]]

    print(multiplication_matrix(a, b))
