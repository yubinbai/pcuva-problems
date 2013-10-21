import sys

sys.stdin = open('input.txt')
for _ in range(int(input())):
    a, b, n, m = map(int, raw_input().split())
    for _ in range(n - 1):
        a, b = b % 10 ** m, (a + b) % 10 ** m
    print b
