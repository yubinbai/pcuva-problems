import sys

sys.stdin = open('input.txt')
while True:
    H, M = map(int, raw_input().strip().split(':'))
    if H == 0 and M == 0:
        break
    a1 = M * 360.0 / 60
    a2 = H * 360.0 / 12 + M / 60.0 * 360 / 12
    a = abs(a1 - a2)
    print '%.3f' % min(360 - a, a)
