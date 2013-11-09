import sys
import math

sys.stdin = open('input.txt')
while True:
    a, b = map(int, raw_input().split())
    if not a and not b:
        break
    print '%.0f' % (math.floor(math.sqrt(b)) - math.ceil(math.sqrt(a)) + 1)
