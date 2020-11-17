import random

rps = {"rock": 0, "paper": 1, "scissors": 2}

computer = random.randint(0, 2)

selection = input("(rock, paper, scissors) Choose one: ")

selection_index = rps[selection]

print(selection, computer)
print("player:", selection, ", computer:", list(rps)[computer])

if computer == selection_index:
    print("draw")
elif (computer == 0 and selection_index == 1) \
        or (computer == 1 and selection_index == 2) \
        or (computer == 2 and selection_index == 0):
    print("win")
else:
    print("loose")
