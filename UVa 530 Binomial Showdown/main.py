import sys


def comb(n, k):
    if k > n:
        return 0
    if k > n / 2.0:
        k = n - k
    result = 1
    for i in range(k):
        result *= (n - i)
        result /= (i + 1)
    return result


sys.stdin = open('input.txt')
while True:
    n, k = map(int, raw_input().split())
    if not n and not k:
        break
    print comb(n, k)
