import sys
from collections import Counter

sys.stdin = open('input.txt')
while True:
    try:
        w1 = raw_input().strip()
        w2 = raw_input().strip()
    except:
        break
    c1 = Counter(w1)
    c2 = Counter(w2)
    k1 = sorted(c1.values())
    k2 = sorted(c2.values())
    if k1 == k2:
        print 'YES'
    else:
        print 'NO'
