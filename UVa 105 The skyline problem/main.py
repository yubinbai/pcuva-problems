from numpypy import *
import sys
MAXN = 10005

sys.stdin = open('input.txt')
H = zeros((MAXN), dtype=int)
for line in sys.stdin:
    left, height, right = map(int, line.split())
    for i in range(left, right + 1):
        H[i] = max(H[i], height)

start = 0
while H[start] == 0:
    start += 1
print '%d %d' % (start, H[start]),
for i in range(start + 1, MAXN):
    if H[i] != H[i - 1]:
        if H[i - 1] < H[i]:
            print '%d %d' % (i, H[i]),
        else:
            print '%d %d' % (i - 1, H[i]),
