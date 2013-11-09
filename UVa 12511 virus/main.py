import sys
import numpypy as np


def lis(array):
    memo = [1]  # longest sequence ending at certain position
    for i in range(1, len(array)):
        currMax = 1
        for j in range(i):
            if array[i] >= array[j] and currMax < memo[j] + 1:
                currMax = memo[j] + 1
        memo.append(currMax)
    return max(memo)


def lcs(one, two):
    def _lcs(p1, p2):
        if p1 == -1 or p2 == -1:
            return 0
        if memo[p1][p2] != 0:
            return memo[p1][p2]
        if one[p1] == two[p2]:
            record[p1][p2] = 0
            memo[p1][p2] = 1 + _lcs(p1 - 1, p2 - 1)
            return memo[p1][p2]
        else:
            left = _lcs(p1 - 1, p2)
            right = _lcs(p1, p2 - 1)
            if left >= right:
                record[p1][p2] = 1
                memo[p1][p2] = left
                return left
            else:
                record[p1][p2] = 2
                memo[p1][p2] = right
                return right
    n1 = len(one)
    n2 = len(two)
    memo = [[0 for x in range(n2)] for y in range(n1)]
    record = [[0 for x in range(n2)] for y in range(n1)]

    _lcs(n1 - 1, n2 - 1)

    result = []
    p1 = n1 - 1
    p2 = n2 - 1
    while p1 >= 0 and p2 >= 0:
        if record[p1][p2] == 0:  # keep
            result.append(one[p1])
            p1 -= 1
            p2 -= 1
        elif record[p1][p2] == 1:  # one is shortened
            p1 -= 1
        else:  # '2', two is shortened
            p2 -= 1
    return result[::-1]


sys.stdin = open('input.txt')
for _ in range(int(input())):
    a = map(int, raw_input().split())
    b = map(int, raw_input().split())
    print lis(lcs(a, b))
