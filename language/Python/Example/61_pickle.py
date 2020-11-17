def pickle01():
    import pickle

    file = open("list.pickle", "wb")
    test = [1, 2, 3, 4, 5]
    pickle.dump(test, file)
    file.close()

    with open("list.pickle", "rb") as file:
        test_pickle = pickle.load(file)
        print(test_pickle)


class Multiply(object):
    def __init__(self, multiplier):
        self.multiplier = multiplier

    def multiply(self, number):
        return number * self.multiplier


def pickle02():
    multiply = Multiply(5)
    print(multiply.multiply(10))

    import pickle

    with open("multiply_object.pickle", "wb") as file:
        pickle.dump(multiply, file)

    with open("multiply_object.pickle", "rb") as file:
        multiply_pickle = pickle.load(file)
        print(multiply_pickle.multiply(5))
