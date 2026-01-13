from cs50 import get_float

while True:
    dollar = get_float("Change:")
    if dollar >= 0:
        break

if dollar == 0:
    print(0)

change = int(round(dollar*100))

i = 0

while change >= 25:
    i += 1
    change -= 25

while change >= 10:
    i += 1
    change -= 10

while change >= 5:
    i += 1
    change -= 5
while change >= 1:
    i += 1
    change -= 1
print(i)
