from numpypy import *
import sys
INF = 1 << 30


def cost(s1, s2):
    N = len(s1)
    M = len(s2)
    memo = empty((N + 1, M + 1), dtype=int)
    memo.fill(-1)

    def dp(i, j):
        if i == 0:
            return j * -7
        if j == 0:
            return i * -7
        if memo[i, j] != -1:
            return memo[i, j]
        if s1[i - 1] == s2[j - 1]:
            memo[i, j] = max(
                dp(i - 1, j - 1) + 5, dp(i, j - 1) - 7, dp(i - 1, j) - 7)
        else:
            memo[i, j] = max(
                dp(i - 1, j - 1) - 4, dp(i, j - 1) - 7, dp(i - 1, j) - 7)
        return memo[i, j]
    return dp(N, M)


def solve(q):
    currMax, maxList = -1 * INF, []
    for s in seq:
        m = cost(q, s)
        if m > currMax:
            currMax, maxList = m, [s]
        elif m == currMax:
            maxList.append(s)
    result = []
    result.append('The query sequence is:\n%s' % q)
    result.append('The most similar sequences are:')
    for m in maxList:
        result.append('%s\nThe similarity score is: %d' % (m, currMax))
    return '\n'.join(result)


sys.stdin = open('input.txt')
query = []
seq = []
isQuery = False
for line in sys.stdin:
    line = line.strip()
    if line[:2] == '>s':
        isQuery = False
    elif line[:2] == '>q':
        isQuery = True
    else:
        if isQuery:
            query.append(line)
        else:
            seq.append(line)

for q in query:
    print(solve(q))
