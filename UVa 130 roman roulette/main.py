import sys


def josephus(n, k):
    r = 0
    i = 2
    while i <= n:
        r = (r + k) % i
        i += 1
    return r + 1

sys.stdin = open('input.txt')
while True:
    n, k = map(int, raw_input().split())
    if not n or not k:
        break
    print josephus(n, k)
