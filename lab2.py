n = int(input("Enter a number between 10 and 100: "))

while n < 10 or n > 100:
    n = int(input("Invalid. Enter a number between 10 and 100: "))

fizz = 0
buzz = 0
fizzbuzz = 0

for i in range(1, n + 1):

    if i % 7 == 0:
        continue

    if i % 3 == 0 and i % 5 == 0:
        print("FizzBuzz")
        fizzbuzz += 1

    elif i % 3 == 0:
        print("Fizz")
        fizz += 1

    elif i % 5 == 0:
        print("Buzz")
        buzz += 1

    else:
        print(i)

print("Fizz count:", fizz)
print("Buzz count:", buzz)
print("FizzBuzz count:", fizzbuzz)