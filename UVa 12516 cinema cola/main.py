'''
thought as dfs, actually a simple simulation problem
'''

import sys

sys.stdin = open('input.txt')


arr = [[False] * 100 for _ in range(27)]
seats = [[False] * 100 for _ in range(27)]
while True:
    rows, cols = map(int, raw_input().split())
    if (rows == 0 and cols == 0):
        break

    for _ in range(int(input())):
        rc, sign = raw_input().split()
        rowIn, colIn = ord(rc[0]) - 65, int(rc[1])
        if sign == '+':
            arr[rowIn][colIn] = True
        else:
            arr[rowIn][colIn - 1] = True

    for _ in range(int(input())):
        rc = raw_input()
        rowIn, colIn = ord(rc[0]) - 65, int(rc[1])
        seats[rowIn][colIn] = True

    canWe = True
    for r in range(rows):
        for c in range(1, cols + 1):
            if seats[r][c]:
                if not arr[r][c - 1]:
                    arr[r][c - 1] = True
                elif not arr[r][c]:
                    arr[r][c] = True
                else:
                    canWe = False
                    break
        if not canWe:
            break
    if (canWe):
        print 'YES'
    else:
        print 'NO'
