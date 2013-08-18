import sys
from numpypy import *
INF = 1 << 31


def solve(par):
    N, M, mat = par
    prev = empty((N, M), dtype=byte)
    prev.fill(-1)

    for j in range(1, M):
        for i in range(N):
            currMin = INF
            idxList = [(i - 1 + N) % N, i, (i + 1) % N]
            idxList.sort()
            for i1 in idxList:
                if mat[i1, j - 1] < currMin:
                    prev[i, j] = i1
                    currMin = mat[i1, j - 1]
            mat[i, j] += currMin
    currMin = INF
    idx = -1
    for i in range(N):
        if mat[i, M - 1] < currMin:
            idx, currMin = i, mat[i, M - 1]
    path = []
    for j in range(M - 1, -1, -1):
        path.append(str(idx + 1))
        idx = prev[idx, j]
    path.reverse()
    return '%s\n%d' % (' '.join(path), currMin)

if __name__ == '__main__':

    sys.stdin = open('input.txt', 'r')
    while True:
        try:
            N, M = map(int, raw_input().split())
        except:
            break
        l = []
        while len(l) < N * M:
            l.extend(map(int, raw_input().split()))
        mat = empty((N, M), dtype=int)

        it = iter(l)
        for i in range(N):
            for j in range(M):
                mat[i, j] = it.next()

        print(solve((N, M, mat)))
