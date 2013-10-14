'''
Created on Jul 19, 2013
@author: Yubin Bai
'''
import sys
INF = 1 << 31


def solve(par):
    N, C, array = par
    array = [0] + array + [N]
    memo = {}

    def _memo(left, right):
        if (left, right) in memo:
            return memo[(left, right)]
        if left == right - 1:
            return 0
        minCost = INF
        for cut in range(left + 1, right):
            cost = _memo(left, cut) + _memo(cut, right)
            minCost = min(cost, minCost)
        minCost += array[right] - array[left]
        memo[(left, right)] = minCost
        return minCost

    return 'The minimum cutting is %d.' % _memo(0, len(array) - 1)


if __name__ == '__main__':
    sys.stdin = open('input.txt', 'r')
    while True:
        N = int(input())
        if N == 0:
            break
        C = int(input())
        array = map(int, raw_input().split())
        print(solve((N, C, array)))
