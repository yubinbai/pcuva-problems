import sys
from numpypy import *
INF = 1 << 31


def solve(par):
    N, L, C, array = par
    numL = 0
    remain = 0
    for a in array:
        if remain < a:
            remain = L
            numL += 1
        remain -= a
    for i in range(1, N):
        array[i] += array[i - 1]
    dp = empty((numL, N + 1), dtype=int64)
    dp.fill(INF)

    def solve(l, start):
        '''
        start lecture l with 'start'
        '''
        if l == numL:
            if start == N:
                return 0
            else:
                return INF
        if dp[l, start] != INF:
            return dp[l, start]
        currMin = INF
        for end in range(start, N):
            if start > 0:
                s = array[end] - array[start - 1]
            else:
                s = array[end]
            if s <= L:
                v = solve(l + 1, end + 1)
                if L - s > 10:
                    v += (L - s - 10) ** 2
                elif L - s <= 10 and L - s > 0:
                    v -= C
                currMin = min(currMin, v)
            else:
                break

        dp[l, start] = currMin
        return currMin

    return 'Minimum number of lectures: %d\nTotal dissatisfaction index: %d' %\
        (numL, solve(0, 0))

if __name__ == '__main__':
    sys.stdin = open('input.txt', 'r')
    while True:
        N = int(input())
        if N == 0:
            break
        L, C = map(int, raw_input().split())
        array = []
        for i in range(N):
            array.append(int(input()))
        print(solve((N, L, C, array)))
