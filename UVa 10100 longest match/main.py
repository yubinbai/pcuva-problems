import sys
import re
import numpypy as np


def lcsLength(line1, line2):
    N = len(line1)
    M = len(line2)
    memo = np.zeros((N + 1, M + 1), dtype=int)
    for i in range(1, N + 1):
        for j in range(1, M + 1):
            if line1[i - 1] == line2[j - 1]:
                memo[i, j] = memo[i - 1, j - 1] + 1
            else:
                memo[i, j] = max(memo[i, j - 1], memo[i - 1, j])
    return memo[N, M]


sys.stdin = open('input.txt')
itertest = 0
while True:
    try:
        line1 = raw_input().strip()
        line2 = raw_input().strip()
    except:
        break
    itertest += 1
    line1 = (re.findall('\w+', line1))
    line2 = (re.findall('\w+', line2))
    if not line1 or not line2:
        print '%d. Blank!' % itertest
    else:
        print '%d. Length of longest match: %d' % (itertest, lcsLength(line1, line2))
