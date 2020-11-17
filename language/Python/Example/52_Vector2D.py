class Vector2D:
    def __init__(self, x, y):
        self.x = x
        self.y = y

    def __add__(self, other):
        x = self.x + other.x
        y = self.y + other.y

        return Vector2D(x, y)

    def __sub__(self, other):
        x = self.x - other.x
        y = self.y - other.y

        return Vector2D(x, y)

    def __eq__(self, other):
        return self.x == other.x and self.y == other.y

    def __str__(self):
        return "(%f, %f)" % (self.x, self.y)
