from numpypy import *
import sys

N = 100
sys.stdin = open('input.txt')


def rot90(mat, N):
    for x in range(N // 2):
        for y in range(N // 2):
            t = mat[x, y]
            mat[x, y] = mat[N - 1 - y, x]
            mat[N - 1 - y, x] = mat[N - 1 - x, N - 1 - y]
            mat[N - 1 - x, N - 1 - y] = mat[y, N - 1 - x]
            mat[y, N - 1 - x] = t


mat = zeros((N, N), dtype=int)
iterline = 0
for line in sys.stdin:
    for i, c in enumerate(line.strip()):
        mat[iterline, i] = ord(c)
    iterline += 1
rot90(mat, N)
for i in range(N):
    line = []
    for j in range(N):
        if mat[i, j]:
            line.append(chr(mat[i, j]))
    if line:
        print ''.join(line)
