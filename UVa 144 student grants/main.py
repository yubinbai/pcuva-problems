import sys
from collections import deque

sys.stdin = open('input.txt')
while True:
    n, k = map(int, raw_input().split())
    if not n and not k:
        break
    q = deque(zip(range(1, n + 1), [40] * n))
    rep = k * (1 + k) / 2
    result = []
    remain = rep
    while q:
        a, b = q.popleft()
        if remain >= b:
            remain -= b
            result.append(a)
            if not remain:
                remain = rep
        else:
            remain = rep
            q.append((a, b - remain))
    print ''.join(['%3d' % a for a in result])
