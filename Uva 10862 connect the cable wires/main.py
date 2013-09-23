import sys


def fib(n):
    a, b = 0, 1
    for i in range(n):
        a, b = b, a + b
        yield b

fibArray = list(fib(4005))
sys.stdin = open('input.txt')
while True:
    N = int(input())
    if not N:
        break
    print fibArray[(N - 1) * 2]
