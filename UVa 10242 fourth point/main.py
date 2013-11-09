import sys

sys.stdin = open('input.txt')
while True:
    try:
        x1, y1, x2, y2, x3, y3, x4, y4 = map(
            float, raw_input().strip().split())
    except:
        break
    if (x1, y1) == (x3, y3):
        x1, y1, x2, y2 = x2, y2, x1, y1
    if (x1, y1) == (x4, y4):
        x1, y1, x2, y2 = x2, y2, x1, y1
        x3, y3, x4, y4 = x4, y4, x3, y3
    if (x2, y2) == (x4, y4):
        x3, y3, x4, y4 = x4, y4, x3, y3
    print '%.3f %.3f' % (x1 + x4 - x2, y1 + y4 - y2)
