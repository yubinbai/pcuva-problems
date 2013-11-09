import sys

sys.stdin = open('input.txt')
while True:
    L = int(input())
    if not L:
        break
    A = raw_input().strip()
    r, d = 0, 0
    res = 1 << 31
    for i, c in enumerate(A):
        if c == 'Z':
            res = 0
            break
        if c == 'R':
            r = i
        elif c == 'D':
            d = i
            res = min(res, d - r)
    print res
