import sys
import math


def allFactors(number):
    result = []
    for i in range(1, int(math.sqrt(number)) + 1):
        a, b = divmod(number, i)
        if b == 0 and i <= a:
            result.append(i)
            if a != i:
                result.append(a)
    result.sort()
    return result

sys.stdin = open('input.txt')
for case in range(1, int(input()) + 1):
    c, r = map(int, raw_input().split())
    n = c - r
    print 'Case #%d:' % case,
    if n == 0:
        print
    else:
        for f in reversed(allFactors(n)):
            if n // f > r:
                print n // f,
        print
