import sys
import math

sys.stdin = open('input.txt')
while True:
    try:
        r, n = map(int, raw_input().split())
    except:
        break
    theta = 2 * math.pi / n
    print '%.3f' % (n * 0.5 * r * r * math.sin(theta))
