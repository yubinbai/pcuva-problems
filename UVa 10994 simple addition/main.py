import sys


def f(n):
    if not n:
        return 0
    elif n % 10:
        return n % 10
    else:
        return f(n // 10)

sys.stdin = open('input.txt')
while True:
    a, b = map(int, raw_input().split())
    if a == -1 and b == -1:
        break
    print sum(f(c) for c in range(a, b + 1))
