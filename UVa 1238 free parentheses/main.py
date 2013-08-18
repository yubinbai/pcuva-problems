'''
Created on Jul 19, 2013
@author: Yubin Bai
'''
import sys
from numpypy import *
INF = 1 << 31
memo = zeros((61, 31, 7005), dtype=byte)
reached = zeros((7005), dtype=byte)


def solve(par):
    exp = par
    n = []
    op = []
    for i, e in enumerate(exp):
        if i % 2:
            if e == '+':
                op.append(1)
            else:
                op.append(-1)
        else:
            n.append(int(e))
    del n[0]
    N = len(n) + 2
    memo.fill(0)
    reached.fill(0)

    def _memo(idx, openBrac, val):
        if memo[idx, openBrac, val] != 0:
            return
        memo[idx, openBrac, val] = 1
        if idx == len(op):
            reached[val] = 1
            return

        nval = val + n[idx] * op[idx] * (-1) ** (openBrac % 2)

        if (op[idx] == -1):  # option 1: put openBrac bracket only if sign is -
            _memo(idx + 1, openBrac + 1, nval)  # no effect if sign is +
        if (openBrac > 0):
         # option 2: put close bracket, can only do this if we already have
         # some openBrac
            _memo(idx + 1, openBrac - 1, nval)
        _memo(idx + 1, openBrac, nval)  # option 3: normal, do nothing
    _memo(0, 0, 0)

    counter = 0
    for i in range(7005):
        if reached[i]:
            counter += 1
    return counter

if __name__ == '__main__':
    sys.stdin = open('input.txt', 'r')
    for line in sys.stdin:
        if line.strip() != '':
            exp = line.strip().split()
            print(solve(exp))
