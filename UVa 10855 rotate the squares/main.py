import sys
import math


def rotateMatrix(mat, n):
    for i in range(n):
        mat[i] = list(mat[i])
    for x in range(int(math.ceil(n / 2.0))):
        for y in range(int(math.floor(n / 2.0))):
            swap = mat[x][y]
            mat[x][y] = mat[n - 1 - y][x]
            mat[n - 1 - y][x] = mat[n - 1 - x][n - 1 - y]
            mat[n - 1 - x][n - 1 - y] = mat[y][n - 1 - x]
            mat[y][n - 1 - x] = swap
    for i in range(n):
        mat[i] = ''.join(mat[i])
    return mat

sys.stdin = open('input.txt')
while True:
    n, m = map(int, raw_input().split())
    if not m and not n:
        break
    nMat = []
    for _ in range(n):
        nMat.append(raw_input().strip())
    mMat = []
    for _ in range(m):
        mMat.append(raw_input().strip())
    for _ in range(4):
        counter = 0
        for i in range(n - m + 1):
            for j in range(n - m + 1):
                flag = True
                for k in range(m):
                    if nMat[i + k][j:j + m] != mMat[k]:
                        flag = False
                        break
                if flag:
                    counter += 1
        print counter,
        mMat = rotateMatrix(mMat, m)
    print
