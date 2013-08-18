'''
Created on Jul 21, 2013
@author: Yubin Bai
'''
import sys
INF = 1 << 31
MAXW = 3005


def solve(par):
    N = int(par * 100)
    values = [10000, 5000, 2000, 1000, 500, 200, 100, 50, 20, 10, 5]
    M = len(values)
    memo = []
    for x in xrange(M):
        memo.append([0] * 30001)

    def dp(step, remain):
        if remain < 0:
            return 0
        elif remain == 0:
            return 1
        if memo[step][remain]:
            return memo[step][remain]
        currSum = 0
        for i in range(step, M):
            if remain >= values[i]:
                currSum += dp(i, remain - values[i])
        memo[step][remain] = currSum
        return currSum

    return dp(0, N)


if __name__ == '__main__':
    sys.stdin = open('input.txt', 'r')

    while True:
        N = float(input())
        if N == 0:
            break
        print('%.2f %d' % (N, solve(N)))
