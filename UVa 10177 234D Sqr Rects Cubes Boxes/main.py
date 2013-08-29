import sys

sys.stdin = open('input.txt')
while True:
    try:
        N = int(input())
    except:
        break
    a1 = sum(range(1, N + 1))
    a2 = sum(map(lambda x: x ** 2, range(1, N + 1)))
    a3 = sum(map(lambda x: x ** 3, range(1, N + 1)))
    a4 = sum(map(lambda x: x ** 4, range(1, N + 1)))
    print a2, a1 ** 2 - a2, a3, a1 ** 3 - a3, a4, a1 ** 4 - a4
