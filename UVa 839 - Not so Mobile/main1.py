import sys
from collections import namedtuple


def weight():
    try:
        wl, dl, wr, dr = map(int, raw_input().split())
    except:
        return True, 0
    leftB = rightB = True
    if not wl:
        leftB, wl = weight()
    if not wr:
        rightB, wr = weight()
    if wl * dl == wr * dr and leftB and rightB:
        return True, wl + wr
    else:
        return False, -1

sys.stdin = open('input.txt')
numTest = int(input())
raw_input()
for itertest in range(numTest):
    correct, w = weight()
    if correct:
        print 'YES'
    else:
        print 'NO'
