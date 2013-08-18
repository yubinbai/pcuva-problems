'''
Created on Jul 24, 2013
@author: Yubin Bai
'''
import sys
from numpypy import *
INF = 1 << 31


def solve(par):
    N, array = par

    # convert to sum array
    for i in range(1, N):
        array[i] += array[i - 1]

    def sumA(i, j):
        if i == 0:
            return array[j]
        else:
            return array[j] - array[i - 1]

    dp = empty((N, N), dtype=int64)
    dp.fill(-1 * INF)
    # state: left, right

    def solve(left, right):
        if left > right:
            return 0
        elif left == right:
            return sumA(left, right)

        if dp[left, right] != -1 * INF:
            return dp[left, right]
        currMax = -1 * INF
        for i in range(left, right):
            profit = sumA(left, i) - solve(i + 1, right)
            profit1 = sumA(i, right) - solve(left, i - 1)
            currMax = max(currMax, profit, profit1)
        dp[left, right] = currMax
        return currMax

    return solve(0, N - 1)


if __name__ == '__main__':
    sys.stdin = open('input.txt', 'r')
    while True:
        N = int(input())
        if N == 0:
            break
        array = map(int, raw_input().split())
        print(solve((N, array)))
