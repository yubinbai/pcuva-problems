def gcd(a, b):
    while b:
        a, b = b, a % b
    return a


def lcm(a, b):
    return a * b / gcd(a, b)
for i in range(2, 11):
    print i - 1, reduce(lcm, range(1, i))
