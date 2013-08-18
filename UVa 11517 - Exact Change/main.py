'''
Created on Jul 22, 2013

@author: Yubin Bai

All rights reserved.
'''
import sys
INF = 1 << 30
MAXN = 10005


def solve(par):
    total, value = par
    M = len(value)
    memo = [INF] * MAXN
    memo[0] = 0
    for v in value:
        for j in range(v, MAXN):
                memo[j] = min(memo[j], memo[j - v] + 1)
    pos = total
    while pos < MAXN and memo[pos] == INF:
        pos += 1
    return '%d %d' % (pos, memo[pos])


if __name__ == '__main__':

    sys.stdin = open('input.txt', 'r')
    numTests = int(input())
    for i in range(numTests):
        total = int(input())
        value = []
        for i in range(int(input())):
            value.append(int(input()))

        print(solve((total, value)))
