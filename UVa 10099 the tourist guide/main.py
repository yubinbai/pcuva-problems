import sys
import math
import numpypy as np

sys.stdin = open('input.txt')
while True:
    N, R = map(int, raw_input().split())
    if not N and not R:
        break
    w = np.zeros((N, N))
    for _ in range(R):
        a, b, w1 = map(int, raw_input().split())
        w[a - 1, b - 1] = w1
        w[b - 1, a - 1] = w1
    s, d, t = map(int, raw_input().split())
    for k in range(N):
        for i in range(N - 1):
            for j in range(i + 1, N):
                w[i, j] = max(w[i, j], min(w[i, k], w[k, j]))
    print '%.f' % math.ceil(t / (w[s - 1, d - 1] - 1))
