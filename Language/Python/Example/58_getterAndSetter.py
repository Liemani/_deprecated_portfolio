class Person:
    def __init__(self):
        self.__age = 0

    @property
    def age(self):
        return self.__age

    @age.setter
    def age(self, value):
        self.__age = value


def test20():
    james = Person()
    james.age = 20
    print(james.age)
