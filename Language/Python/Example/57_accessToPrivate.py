class Inventory(object):
    def __init__(self):
        self.__items = []

    @property
    def items(self):
        return self.__items


def test19():
    inventory = Inventory()
    inventory.items = [1]
