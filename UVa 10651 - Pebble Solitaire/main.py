'''
Created on Jul 24, 2013
@author: Yubin Bai
'''
import sys
from numpypy import *
INF = 1 << 31
MAXN = 12


def count1(number):
    counter = 0
    while number != 0:
        number &= number - 1
        counter += 1
    return counter


def solve(par):
    state = par
    if dp[state] != 255:
        return dp[state]
    currMin = count1(state)
    if currMin <= 1:
        dp[state] == currMin
        return currMin
    for i in range(MAXN):
        i1, i2, i3 = i - 1, i, i + 1
        if not (1 << i) & state:
            continue
        if i - 2 in range(MAXN) and not ((1 << (i - 2)) & state)\
                and ((1 << (i - 1)) & state):
            currMin = min(
                currMin, solve(state & ~(1 << i) & ~(1 << (i - 1)) | (1 << (i - 2))))
        if i + 2 in range(MAXN) and not ((1 << (i + 2)) & state)\
                and ((1 << (i + 1)) & state):
            currMin = min(
                currMin, solve(state & ~(1 << i) & ~(1 << (i + 1)) | (1 << (i + 2))))
    dp[state] = currMin
    return currMin


if __name__ == '__main__':
    dp = empty((1 << MAXN), dtype=int)
    dp.fill(255)

    sys.stdin = open('input.txt', 'r')
    numTest = int(input())
    for itertest in range(numTest):
        row = raw_input().strip()
        state = int(row.replace('-', '0').replace('o', '1'), base=2)
        print(solve(state))
