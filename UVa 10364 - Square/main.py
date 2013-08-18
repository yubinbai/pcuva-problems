'''
Created on Jul 24, 2013
@author: Yubin Bai
'''
import sys
from numpypy import *
INF = 1 << 31


def solve(par):
    def calc(state, side):
        s = 0
        for i in range(N):
            if state & (1 << i):
                s += sides[i]
        return s - side * sideL

    def can(side, state):
        left = calc(state, side)
        if left == sideL:
            return can(side + 1, state)
        elif side == 4:
            return 1
        elif dp[side, state] != -1:
            return dp[side, state]
        else:
            result = 0
            for i in range(N):
                if not (state & (1 << i)) and left + sides[i] <= sideL:
                    result |= can(side, state | (1 << i))
            dp[side, state] = result
            return result

    N, sides = par
    s = sum(sides)
    if s % 4 != 0:
        return 'no'
    sideL = s // 4
    dp = empty((4, 1 << 21), dtype=byte)
    dp.fill(-1)
    if can(0, 0):
        return 'yes'
    else:
        return 'no'


if __name__ == '__main__':
    sys.stdin = open('input.txt', 'r')
    numTest = int(input())
    for itertest in range(numTest):
        row = map(int, raw_input().split())
        N = row[0]
        sides = row[1:]

        print(solve((N, sides)))
