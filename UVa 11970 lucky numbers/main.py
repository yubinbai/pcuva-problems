import sys
import bisect

sq = map(lambda x: x ** 2, range(100000))
sys.stdin = open('input.txt')
for case in range(1, 1 + int(input())):
    n = int(input())
    idx = bisect.bisect_left(sq, n)
    if n == sq[idx]:
        idx -= 1
    res = []
    for i in range(idx, 0, -1):
        if (n - sq[i]) % i == 0:
            res.append(n - sq[i])
    print 'Case %d: %s' % (case, ' '.join(map(str, res)))
