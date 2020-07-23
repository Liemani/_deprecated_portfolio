def print_numbers(a=0, b=0, c=0):
    print(a)
    print(b)
    print(c)


def test15():
    x = [10, 20, 30]
    print_numbers(*x)


def test15_2():
    x = (10, 20, 30)
    print_numbers(*x)


def test16():
    print_numbers(*[10, 20, 30])


def test16_2():
    print_numbers(*(10, 20, 30))


def test17():
    x = {"a": 10, "b": 20, "c": 30}
    print_numbers(**x)


def test18():
    print_numbers(**{"a": 10, "b": 20, "c": 30})


def test19():
    print_numbers(a=10, b=20, c=30)


def test20():
    print_numbers(b=20)


def test21():
    print_numbers(10, 20)


def tuple_argument(*args):
    x, y, z = args
    return x + y + z


def tuple_argument2(*args):
    x, y, *z = args
    return x + y + sum(z)


def test22():
    print(tuple_argument(1, 2, 3))


def test23():
    print(tuple_argument2(1, 2, 3, 4, 5))


def keyword_tuple(**kwargs):
    print("name:", kwargs["name"])
    print("age:", kwargs["age"])


def test24():
    keyword_tuple(name="lieman", age=28)


def keyword_tuple2(**kwargs):
    print("food: {foodname}, color: {foodcolor}".format(**kwargs))
    print("beverage: {beveragename}, color: {beveragecolor}".format(**kwargs))


def test25():
    data = {"foodname": "banana", "foodcolor": "yellow",
            "beveragename": "coke", "beveragecolor": "black"}
    keyword_tuple2(**data)
