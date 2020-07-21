import datetime

now = datetime.datetime.now()

current_time = now.strftime("%Y:%H:%M:%S")
print("Current Time=", current_time)

year = 2020
month = 7
day = 21

hour = 10
minute = 41
second = 15

print(year, month, day, sep='/', end=' ')
print(hour, minute, second, sep=':')
