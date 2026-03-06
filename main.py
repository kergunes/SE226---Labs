x = int(input("Please enter a positive integer greater than 9: "))

steps = 0
print(x, end="")

while x >= 10:
    y = 0
    temp = x

    while temp > 0:
        y += temp % 10
        temp = temp // 10

    x = y
    steps += 1
    print(" →", x, end="")

print()
print("Final value:", x)
print("Total steps:", steps)