'''
Created on Jul 27, 2013
@author: Yubin Bai
'''
import sys
from numpypy import *
INF = 1 << 30

if __name__ == '__main__':
    sys.stdin = open('input.txt', 'r')
    while True:
        C, S, E, T = map(int, raw_input().split())
        if C == 0:
            break
        graph = zeros((C + 1, C + 1), dtype=int)

        for i in range(1, C + 1):
            row = map(int, raw_input().strip().split())
            for j in range(1, C + 1):
                graph[i, j] = row[j - 1]
        end = map(int, raw_input().split())
        raw_input()

        dp = empty((C + 1, T + 1), dtype=int)
        dp.fill(-1 * INF)
        dp[S, 0] = 0
        for d in range(1, T + 1):
            for c in range(1, C + 1):
                for c1 in range(1, C + 1):
                    if c1 != c:
                        dp[c, d] = max(dp[c, d], dp[c1, d - 1] + graph[c1, c])
        print(max(dp[e, T] for e in end))
