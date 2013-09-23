from bitstring import BitArray
from math import *
import sys


def fillTree(s, pos, tree, root):
    '''
    fill tree and return finished pos
    '''
    if s[pos] == 'p':
        pos1 = fillTree(s, pos + 1, tree, root * 4 + 1)
        pos1 = fillTree(s, pos1, tree, root * 4 + 2)
        pos1 = fillTree(s, pos1, tree, root * 4 + 3)
        pos1 = fillTree(s, pos1, tree, root * 4 + 4)
        return pos1
    elif s[pos] == 'f':
        tree.set(True, root)
        return pos + 1
    else:
        return pos + 1


def compTree(t1, t2, r):
    if r >= MAXN:
        return 0
    if t1[r] or t2[r]:
        r1 = r
        p = 0
        while r1 > 0:
            p += 1
            r1 = (r1 - 1) // 4
        # print r, (r - 1) // 4, p, 1024 / (4 ** p)
        return 1024 / (4 ** p)
    else:
        s = 0
        s += compTree(t1, t2, r * 4 + 1)
        s += compTree(t1, t2, r * 4 + 2)
        s += compTree(t1, t2, r * 4 + 3)
        s += compTree(t1, t2, r * 4 + 4)
        return s


MAXN = 1511
sys.stdin = open('input.txt')
numTest = int(input())
for itertest in range(numTest):
    t1 = raw_input().strip()
    tree1 = BitArray(MAXN)
    fillTree(t1, 0, tree1, 0)
    t2 = raw_input().strip()
    tree2 = BitArray(MAXN)
    fillTree(t2, 0, tree2, 0)
    result = 1
    print compTree(tree1, tree2, 0)
