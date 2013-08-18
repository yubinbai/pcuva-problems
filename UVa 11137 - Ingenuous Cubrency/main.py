import sys
from numpypy import *
INF = 1 << 31
MAXN = 10005


if __name__ == '__main__':
    values = [i ** 3 for i in range(1, 22)]
    memo = [0] * MAXN
    memo[0] = 1
    for v in values:
        for i in range(v, MAXN):
            memo[i] += memo[i - v]

    sys.stdin = open('input.txt', 'r')
    while True:
        try:
            N = int(input())
        except:
            break
        print(memo[N])
