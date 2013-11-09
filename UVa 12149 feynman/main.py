import sys

sys.stdin = open('input.txt')
while True:
    n = int(input())
    if not n:
        break
    print sum(map(lambda x: x ** 2, range(1, n + 1)))
