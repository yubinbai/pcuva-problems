import numpy as np

import sys
N = 100
sys.stdin = open('input.txt')
mat = np.zeros((N, N), dtype=int)
iterline = 0
for line in sys.stdin:
    for i, c in enumerate(line.strip()):
        mat[iterline, i] = ord(c)
    iterline += 1
mat = np.rot90(mat, 3)
for i in range(N):
    line = []
    for j in range(N):
        if mat[i, j]:
            line.append(chr(mat[i, j]))
    if line:
        print ''.join(line)
