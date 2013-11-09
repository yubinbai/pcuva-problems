import sys
import math

sys.stdin = open('input.txt')
case = 0
while True:
    A = map(float, raw_input().strip().split())
    case += 1
    if A[0] == 0:
        break
    if A[0] == 1:
        u, v, t = A[1:]
        print 'Case %d: %.3f %.3f' % (case, 1.0 / 2 * t * (u + v), (v - u) / t)
    if A[0] == 2:
        u, v, a = A[1:]
        print 'Case %d: %.3f %.3f' % (case, (v ** 2 - u ** 2) / 2.0 / a, (v - u) / a)
    if A[0] == 3:
        u, a, s = A[1:]
        print 'Case %d: %.3f %.3f' % (case, math.sqrt(2 * a * s + u ** 2), (math.sqrt(2 * a * s + u ** 2) - u) / a)
    if A[0] == 4:
        v, a, s = A[1:]
        print 'Case %d: %.3f %.3f' % (case, math.sqrt(v ** 2 - 2 * a * s), (v - math.sqrt(v ** 2 - 2 * a * s)) / a)
