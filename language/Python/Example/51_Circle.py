class Circle:
    def __init__(self, radius):
        self.radius = radius

    def __eq__(self, other):
        return self.radius == other.radius
