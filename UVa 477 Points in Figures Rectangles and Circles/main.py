import sys
import math

sys.stdin = open('input.txt')
figures = []
while True:
    line = raw_input().strip().split()
    if line[0] == '*':
        break
    for i in range(1, len(line)):
        line[i] = float(line[i])
    figures.append(line)
p = 1
while True:
    x, y = map(float, raw_input().split())
    if x == 9999.9 and y == 9999.9:
        break
    flag = False
    for i, f in enumerate(figures):
        if f[0] == 'c':
            if math.hypot(x - f[1], y - f[2]) <= f[3]:
                flag = True
                print 'Point %d is contained in figure %d' % (p, i + 1)
        else:
            if x >= f[1] and x <= f[3] and y >= f[4] and y <= f[2]:
                flag = True
                print 'Point %d is contained in figure %d' % (p, i + 1)
    if not flag:
        print 'Point %d is not contained in any figure' % p

    p += 1
