import sys
import math

sys.stdin = open('input.txt')
for _ in range(int(input())):
    s = raw_input().strip()
    n = len(s)
    m = int(math.sqrt(n))
    if m ** 2 != n:
        print 'invalid'
        continue
    res = []
    for i in range(m):
        for j in range(m):
            res.append(s[j * m + i])
    print ''.join(res)
