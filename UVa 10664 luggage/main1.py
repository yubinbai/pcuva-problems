import sys


sys.stdin = open('input.txt')
for _ in range(int(input())):
    w = map(int, raw_input().split())
    s = sum(w)
    n = len(w)
    if s & 1:
        print 'NO'
    else:
        b = 1
        for c in w:
            b |= b << c
        if (1 << (s // 2)) & b:
            print 'YES'
        else:
            print 'NO'
