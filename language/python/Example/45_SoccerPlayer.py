class SoccerPlayer:
    def __init__(self, name, position, back_number):
        self.name = name
        self.position = position
        self.back_number = back_number

    def change_back_number(self, new_number):
        print("old back number: %d" % self.back_number)
        print("new back number: %d" % new_number)

        self.back_number = new_number

    def __str__(self):
        return "Hello! my name is {}. I play in {} in center.".format(self.name, self.position)


def run():
    player = SoccerPlayer("PJH", "back", 91)
    player.change_back_number(0)
    print(player)
