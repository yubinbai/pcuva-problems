import sys
import math

sys.stdin = open('input.txt')
while True:
    n = int(input())
    if not n:
        break
    if n == 1:
        print 'Printing order for 1 pages:\nSheet 1, front: Blank, 1'
        continue
    sheets = int(math.ceil(n / 4.0))
    result = [None] * 2
    result[0] = range(1, min(n + 1, sheets * 2 + 1))
    if n % 4:
        result[1] = ['Blank'] * (4 - n % 4)
    else:
        result[1] = []
    result[1] += range(sheets * 2 + 1, n + 1)[::-1]
    print 'Printing order for %d pages' % n
    for i in range(sheets):
        print 'Sheet %d, front: %s, %s' % \
            (i + 1, result[1][2 * i], result[0][2 * i])
        print 'Sheet %d, back : %s, %s' % \
            (i + 1, result[0][2 * i + 1], result[1][2 * i + 1])
