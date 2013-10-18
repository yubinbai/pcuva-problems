import sys

sys.stdin = open('input.txt')
f = [0, 0, 1, 2]
for i in xrange(4, 805):
    f.append((f[i - 1] + f[i - 2]) * (i - 1))
while True:
    n = int(input())
    if n == -1:
        break
    print f[n]
