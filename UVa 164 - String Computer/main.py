from numpypy import *
import sys

sys.stdin = open('input.txt')
for line in sys.stdin:
    if line.strip() == '#':
        break
    s1, s2 = line.strip().split()
    n = len(s1)
    m = len(s2)
    dist = zeros((n + 1, m + 1), dtype=int)
    dist.fill(-1)
    op = zeros((n + 1, m + 1), dtype=int)

    def dp(i, j):
        if dist[i, j] != -1:
            return dist[i, j]
        if i == n:
            dist[i, j] = m - j
            return dist[i, j]
        if j == m:
            dist[i, j] = n - i
            return dist[i, j]

        if s1[i] == s2[j]:
            dist[i, j] = dp(i + 1, j + 1)
        else:
            dist[i, j] = dp(i + 1, j + 1) + 1

        if dp(i + 1, j) + 1 < dist[i, j]:
            dist[i, j] = dp(i + 1, j) + 1
            op[i, j] = 1  # delete
        if dp(i, j + 1) + 1 < dist[i, j]:
            dist[i, j] = dp(i, j + 1) + 1
            op[i, j] = 2  # insert
        return dist[i, j]
    dp(0, 0)
    # print op
    result = []
    i = j = 0
    while i != n and j != m:
        if op[i, j] == 0:
            if s1[i] != s2[j]:
                result.append('C%s%02d' % (s2[j], j + 1))
            i, j = i + 1, j + 1
        elif op[i, j] == 1:
            result.append('D%s%02d' % (s1[i], j + 1))
            i, j = i + 1, j
        elif op[i, j] == 2:
            result.append('I%s%02d' % (s2[j], j + 1))
            i, j = i, j + 1
    # print dist
    result.append('E')
    print ' '.join(result)
