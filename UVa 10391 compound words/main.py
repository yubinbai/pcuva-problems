import sys
import bisect

sys.stdin = open('input.txt')
d = []
while True:
    try:
        d.append(raw_input().strip())
    except:
        break

s = set(d)
idx = 0
while idx < len(d):
    # print d[idx] + '~'
    i2 = bisect.bisect_right(d, d[idx] + '~')
    # if i2 != idx + 1: print idx, i2
    for i in range(idx + 1, i2):
        if i < len(d) and len(d[idx]) < len(d[i])\
                and d[i][len(d[idx]):] in s:
            print d[i]
    idx = i2
