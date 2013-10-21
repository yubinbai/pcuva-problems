from bitstring import BitArray
import sys

sys.stdin = open('input.txt')
while True:
    w, h, n = map(int, raw_input().split())
    if not any([w, h, n]):
        break
    mat = [BitArray(w) for _ in range(h)]
    for _ in range(n):
        x1, y1, x2, y2 = map(int, raw_input().split())
        x1, x2 = sorted([x1, x2])
        y1, y2 = sorted([y1, y2])
        for i in range(y1 - 1, y2):
            mat[i].set(True, range(x1 - 1, x2))
    total = 0
    for i in range(h):
        total += mat[i].count(False)
    if not total:
        print 'There is no empty spots.'
    elif total == 1:
        print 'There is one empty spot.'
    else:
        print 'There are %d empty spots.' % total
    try:
        raw_input()
    except:
        break
