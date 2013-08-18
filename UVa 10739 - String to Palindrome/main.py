from numpypy import *
import sys
INF = 1 << 30


def editDistance(s1, s2):
    N = len(s1)
    M = len(s2)
    memo = empty((N + 1, M + 1), dtype=int)
    memo.fill(-1)

    def dist(i, j):
        if i == 0:
            return j
        if j == 0:
            return i
        if memo[i, j] != -1:
            return memo[i, j]
        if s1[i - 1] == s2[j - 1]:
            memo[i, j] = min(
                dist(i - 1, j - 1), dist(i - 1, j) + 1, dist(i, j - 1) + 1)
        else:
            memo[i, j] = min(
                dist(i - 1, j - 1), dist(i - 1, j), dist(i, j - 1)) + 1
        return memo[i, j]

    return dist(N, M)


def solve(s):
    N = len(s)
    currMin = INF
    for i in range(N):
        # odd palindrome
        if N - i - (i) < currMin:
            currMin = min(currMin, editDistance(s[:i], s[N - 1:i:-1]))
        # even palindrome
        if N - i - (i + 1) < currMin:
            currMin = min(currMin, editDistance(s[:i], s[N - 1:i - 1:-1]))
    return currMin


sys.stdin = open('input.txt')
numTest = int(input())
for itertest in range(numTest):
    print('Case#%d: %d' % (itertest + 1, solve(raw_input().strip())))
