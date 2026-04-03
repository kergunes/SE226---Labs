def factorial(x):
    if x == 0:
        return 1;

    return x * factorial(x - 1)


absolute = lambda x,i: (x**(2*i)/factorial(2*i))


def exp_x(x,n):
    sum = 0

    for i in range(n):
        sum+=((-1)**i) * (absolute(x,i))
    print(sum)

x=int(input("Please enter x"))
n=int(input("Please enter n"))
exp_x(x,n)
asd = 0

total = 0
def solve_sn(n):
    global result
    if n <= 0:
        return

    solve_sn(n - 1)
    term = ((-1) ** (n + 1)) / n
    result += term


