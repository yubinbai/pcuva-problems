'''
Created on Jul 24, 2013
@author: Yubin Bai
'''
import sys
from numpypy import *
INF = 1 << 31


def solve(par):
    N, array, b, r, v, e, f = par
    dp = empty((N + 1, N + 1))
    dp.fill(INF)
    dp[0, 0] = 0

    def _solve(prev, curr):
        if dp[prev, curr] != INF:
            return dp[prev, curr]

        if prev == 0:
            dist = array[curr - 1]
            time = 0.0
            for x in range(dist):
                if x >= r:
                    time += 1.0 / (v - e * (x - r))
                else:
                    time += 1.0 / (v - f * (r - x))
            dp[prev, curr] = time
            return time

        currMin = INF
        for p in range(prev):
            dist = array[curr - 1] - array[prev - 1]

            time = 0.0
            for x in range(dist):
                if x >= r:
                    time += 1.0 / (v - e * (x - r))
                else:
                    time += 1.0 / (v - f * (r - x))

            currMin = min(currMin, _solve(p, prev) + time + b)
        dp[prev, curr] = currMin
        return currMin

    return '%.5f' % min(_solve(i, N) for i in range(N))

if __name__ == '__main__':
    sys.stdin = open('input.txt', 'r')
    while True:
        N = int(input())
        if N == 0:
            break
        array = map(int, raw_input().split())
        b = float(raw_input())
        r, v, e, f = map(float, raw_input().split())
        print(solve((N, array, b, r, v, e, f)))
