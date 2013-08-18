'''
Created on Jul 19, 2013
@author: Yubin Bai
'''
import sys
from itertools import combinations
from math import sqrt
INF = 1 << 31


def solve(par):
    N, points = par
    N <<= 1
    memo = [INF] * (1 << N)

    def _memo(status):
        if status == (1 << N) - 1:
            return 0
        if memo[status] != INF:
            return memo[status]
        zeros = []
        for i in range(N):
            if not (1 << i & status):
                zeros.append(i)
        minCost = INF
        for i, j in combinations(zeros, 2):
            dist = sqrt(
                (points[i][0] - points[j][0]) ** 2
                + (points[i][1] - points[j][1]) ** 2)
            cost = _memo(status | (1 << i) | (1 << j)) + dist
            minCost = min(minCost, cost)
        memo[status] = minCost
        return minCost
    return '%.2f' % _memo(0)

if __name__ == '__main__':
    sys.stdin = open('input.txt', 'r')
    while True:
        N = int(input())
        if N == 0:
            break
        points = []
        for i in range(N * 2):
            points.append(map(int, raw_input().split()[1:]))
        print(solve((N, points)))
