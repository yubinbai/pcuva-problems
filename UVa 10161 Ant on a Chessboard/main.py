import sys
from math import sqrt, ceil

sys.stdin = open('input.txt')
while True:
    n = int(input())
    if not n:
        break
    pos = int(ceil(sqrt(n)))
    print n, ':',
    remain = n - (pos - 1) ** 2
    if pos % 2:  # col go up first
        if remain <= pos:
            print pos, remain
        else:
            print pos - (remain - pos), pos
    else:  # row go right first
        if remain <= pos:
            print remain, pos
        else:
            print pos, 2 * pos - remain
