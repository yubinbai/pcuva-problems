import sys


def fib(n):
    a, b = 0, 1
    for x in range(n):
        yield b
        a, b = b, a + b
sys.stdin = open('input.txt')
fibArray = list(fib(100))
while True:
    N = int(input())
    if not N:
        break
    print fibArray[N]
