class Block:
    def __init__(self, company, color, shape):
        self.company = company
        self.color = color
        self.shape = shape

    def __str__(self):
        return "[company: {}, color: {}, shape: {}]".format(self.company, self.color, self.shape)


def run():
    block1 = Block("Gole", "blue", "long")
    block2 = Block("Gole", "black", "short")
    block3 = Block("Oxfold", "red", "big")

    print(block1)
    print(block2)
    print(block3)
