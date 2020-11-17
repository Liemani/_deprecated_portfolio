name = input("Enter your name:")

score_korean = int(input("Enter korean score: "))
score_mathmatics = int(input("Enter mathmatics score: "))
score_society = int(input("Enter society score: "))
score_science = int(input("Enter science score: "))
score_english = int(input("Enter english score: "))
score_python = int(input("Enter python score: "))

sum = score_korean \
      + score_mathmatics \
      + score_society \
      + score_science \
      + score_english \
      + score_python

average = sum / 6

print("Score of " + name)
print("Total:", sum, ", Average:", average)