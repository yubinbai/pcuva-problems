import sys
import bisect

sys.stdin = open('input.txt')
case = 0
while True:
    n = int(input())
    case += 1
    if not n:
        break
    r = 4
    while True:
        if r * (r - 1) / 2 - r < n:
            r += 1
        else:
            break
    print 'Case %d: %d' % (case, r)
