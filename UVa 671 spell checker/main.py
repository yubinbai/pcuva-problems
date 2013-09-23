import sys
import numpypy as np


def dist(w1, w2):
    def dp(i, j):
        if memo[i, j] != -1:
            return memo[i, j]
        if i == 0:
            return j
        if j == 0:
            return i
        if w1[i - 1] == w2[j - 1]:
            return min(dp(i - 1, j - 1), dp(i - 1, j) + 1, dp(i, j - 1) + 1)
        else:
            return min(dp(i - 1, j - 1) + 1, dp(i - 1, j) + 1, dp(i, j - 1) + 1)

    len1 = len(w1)
    len2 = len(w2)
    memo = np.empty((len1 + 1, len2 + 1), dtype=int)
    memo.fill(-1)
    return dp(len1, len2)


sys.stdin = open('input.txt')
numTest = int(input())
for itertest in range(numTest):
    raw_input()
    d = set()
    while True:
        w = raw_input().strip()
        if w == '#':
            break
        else:
            d.add(w)
    while True:
        w = raw_input().strip()
        if w == '#':
            break
        if w in d:
            print '%s is correct' % w
        else:
            result = []
            for w2 in d:
                if dist(w, w2) == 1:
                    result.append(w2)
            result.sort()
            print '%s: %s' % (w, ' '.join(result))
