import sys
from collections import Counter

sys.stdin = open('input.txt')
d = {'B': 1, 'U': 10, 'S': 100, 'P': 1000,
     'F': 10000, 'T': 100000, 'M': 1000000}
for _ in range(int(input())):
    s = raw_input().strip()
    total = 0
    er = False
    for k, v in Counter(s).items():
        if v >= 10:
            er = True
            break
        total += d[k] * v
    ordS = ''.join(sorted(list(s), key=lambda x: d[x]))
    if s != ordS and s[::-1] != ordS:
        er = True

    if er:
        print 'error'
    else:
        print total
