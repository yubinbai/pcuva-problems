import sys
import bisect

sys.stdin = open('input.txt')
case = 0
while True:
    n = int(input())
    case += 1
    if not n:
        break
    low = 4
    high = 100000000
    while low < high:
        mid = (low + high) >> 1
        if mid * (mid - 1) / 2 - mid > n:
            high = mid
        else:
            low = mid + 1
    print 'Case %d: %d' % (case, low)
