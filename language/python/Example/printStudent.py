import datetime

thisyear = datetime.datetime.now().year

print("Enter the year of birth")
birth_year = int(input())

age = thisyear - birth_year + 1
if 20 <= age <= 26:
    print("You are a college student")
elif 17 <= age < 20:
    print("You are a high school student")
elif 14 <= age < 17:
    print("You are a middle school student")
elif 8 <= age < 14:
    print("You are an elementary school student")
else:
    print("You are not a student")