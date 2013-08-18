import sys
from numpypy import *


def solve(par):
    mat = par
    N = len(mat)
    memo = zeros((N + 1, N + 1), dtype=int32)  # store the sum of upperleft
    for j in range(1, N + 1):
        if mat[0][j - 1] == '1':
            memo[1, j] = 1
        for i in range(1, N + 1):
            if mat[i - 1][j - 1] == '1':
                memo[i, j] = 1 + memo[i - 1, j]
            else:
                memo[i, j] = memo[i - 1, j]
    for j in range(2, N + 1):
        for i in range(1, N + 1):
            memo[i][j] += memo[i][j - 1]

    currMax = -1
    for i in range(N):
        for j in range(N):
            for i1 in range(i + 1, N + 1):
                for j1 in range(j + 1, N + 1):
                    v = memo[i1, j1] - memo[i, j1] - memo[i1, j] + memo[i, j]
                    if v == (i1 - i) * (j1 - j) and v > currMax:
                        currMax = v
                        # print(i, j, i1, j1)
    return currMax


if __name__ == '__main__':
    sys.stdin = open('input.txt', 'r')
    numTest = int(input())
    raw_input()
    for itertest in range(numTest):
        mat = []
        line = raw_input().strip()
        N = len(line) - 1
        for i in range(N):
            mat.append(raw_input().strip())
        print(solve(mat))
