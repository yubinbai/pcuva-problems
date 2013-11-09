import sys
import math

sys.stdin = open('input.txt')
for case in range(1, 1 + int(input())):
    n = int(input())
    total = 0
    n -= 180000
    if n > 0:
        total += n * 0.1
    n -= 300000
    if n > 0:
        total += n * 0.05
    n -= 400000
    if n > 0:
        total += n * 0.05
    n -= 300000
    if n > 0:
        total += n * 0.05
    if total > 0 and total < 2000:
        total = 2000
    else:
        total = int(math.ceil(total))
    print 'Case %d: %d' % (case, total)
