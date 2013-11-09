import sys

sys.stdin = open('input.txt')
for _ in range(int(input())):
    e, f, c = map(int, raw_input().split())
    total = 0
    n = e + f
    while n > c - 1:
        a, b = divmod(n, c)
        total += a
        n = a + b
    print total
