import sys


def f(x):
    return ((a * x + b) * x + c) % d == 0

sys.stdin = open('input.txt')
while True:
    a, b, c, d, l = map(int, raw_input().split())
    if not any([a, b, c, d, l]):
        break
    counter = 0
    for i in range(l + 1):
        if f(i):
            counter += 1
    print counter
