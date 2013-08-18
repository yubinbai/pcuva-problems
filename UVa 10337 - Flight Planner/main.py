import sys
from numpypy import *
INF = 1 << 31


def solve(par):
    N, M, mat = par
    cost = zeros((N, M + 1), dtype=int64)
    for i in range(N - 1):
        cost[i, 0] = INF
    for j in range(1, M + 1):
        for i in range(N):
            currMin = INF
            costList = [cost[i, j - 1] - mat[i, j - 1] + 30]
            if i > 0:
                costList.append(cost[i - 1, j - 1] - mat[i - 1, j - 1] + 20)
            if i < N - 1:
                costList.append(cost[i + 1, j - 1] - mat[i + 1, j - 1] + 60)
            cost[i, j] = min(costList)

    return '%d\n' % (cost[N - 1, M])

if __name__ == '__main__':

    sys.stdin = open('input.txt', 'r')
    numTest = int(input())
    for itertest in range(numTest):
        raw_input()
        N = 10
        M = int(input()) / 100
        l = []
        for i in range(N):
            l.extend(map(int, raw_input().split()))
        mat = empty((N, M), dtype=int)
        it = iter(l)
        for i in range(N):
            for j in range(M):
                mat[i, j] = it.next()

        print(solve((N, M, mat)))
