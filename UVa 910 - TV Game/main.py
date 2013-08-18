'''
Created on Jul 27, 2013
@author: Yubin Bai
'''
import sys
from numpypy import *
INF = 1 << 30


def solve(par):
    N, M, graph = par
    if M == 0:
        return graph[0, 2]
    dp = zeros((N, M + 1), dtype=int)
    dp[0, 0] = 1
    # state: at pos i for step j
    for j in range(1, M + 1):
        for i in range(N):
            result = 0
            for k in range(N):
                if graph[k, 0] == i:
                    result += dp[k, j - 1]
                if graph[k, 1] == i:
                    result += dp[k, j - 1]
            dp[i, j] = result
    s = 0
    for i in range(N):
        if graph[i, 2]:
            s += dp[i, M]
    return s

if __name__ == '__main__':
    sys.stdin = open('input.txt', 'r')
    while True:
        try:
            N = int(input())
        except:
            break
        graph = zeros((N + 1, 3), dtype=int)

        for i in range(N):
            row = raw_input().strip().split()
            for j in range(1, 3):
                graph[i, j - 1] = ord(row[j]) - ord('A')
            if row[3] == '-':
                graph[i, 2] = 0
            else:
                graph[i, 2] = 1
        M = int(input())
        print(solve((N, M,  graph)))
