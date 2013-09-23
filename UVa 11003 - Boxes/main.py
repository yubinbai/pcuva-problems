'''
Created on Jul 20, 2013
@author: Yubin Bai
'''
import sys
import numpypy as np
INF = 1 << 31
MAXW = 3005


def solve(par):
    N, boxes = par
    memo = np.zeros((N, MAXW), dtype=int)

    def dp(idx, remainW):
        if memo[idx, remainW]:
            return memo[idx, remainW]
        if not remainW:
            return 0
        currMax = 1
        for i in range(idx + 1, N):
            if boxes[i][0] <= remainW:
                m1 = dp(i, remainW - boxes[i][0]) + 1
                currMax = max(currMax, m1)
        memo[idx, remainW] = currMax
        return currMax
    return max(dp(i, boxes[i][1]) for i in range(N))


if __name__ == '__main__':
    sys.stdin = open('input.txt', 'r')
    while True:
        N = int(input())
        if N == 0:
            break
        boxes = []
        for i in range(N):
            boxes.append(map(int, raw_input().split()))
        print(solve((N, boxes)))
