class Vehicle:
    def __init__(self, make, model, color, price):
        self.make = make
        self.model = model
        self.color = color
        self.price = price

    def get_make(self):
        return self.make

    def set_make(self, make):
        self.make = make

    def description(self):
        return "{{\"Vehicle\": {{make: \"{}\", model: \"{}\", color: \"{}\", price: {}}}}}".format(*tuple(map(str, (self.make, self.model, self.color, self.price))))


class Truck(Vehicle):
    def __init__(self, make, model, color, price, payload):
        super().__init__(make, model, color, price)

        self.payload = payload

    def get_payload(self):
        return self.payload

    def set_payload(self, payload):
        self.payload = payload


def run():
    my_truck = Truck("Tisla", "Model S", "white", 10000, 2000)
    my_truck.set_make("Tesla")
    my_truck.set_payload(2000)
    print(my_truck.description())
