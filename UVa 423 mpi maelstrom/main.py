import sys
import numpypy as np

sys.stdin = open('input.txt')
n = int(input())
w = np.zeros((n, n))
for i in range(1, n):
    w[i, i] = 0
    line = raw_input().strip().split()
    for j in range(i):
        if line[j] == 'x':
            w[i, j] = w[j, i] = float('inf')
        else:
            w[i, j] = w[j, i] = int(line[j])
for k in range(n):
    for i in range(n - 1):
        for j in range(i + 1, n):
            w[i, j] = min(w[i, j], w[i, k] + w[k, j])
            w[j, i] = w[i, j]
print '%.f' % w.max()
