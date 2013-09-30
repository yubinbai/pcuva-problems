import sys


def gcd(a, b):
    while b:
        a, b = b, a % b
    return a

sys.stdin = open('input.txt')
while True:
    try:
        x, y = map(int, raw_input().split())
    except:
        break
    result = [x // y]
    x %= y
    g = gcd(x, y)
    x, y = x / g, y / g
    while y > 1:
        result.append(y // x)
        x, y = y % x, x
    print '[%d; %s]' % (result[0], ', '.join(str(i) for i in result[1:]))
