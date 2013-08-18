import sys
import re
from numpypy import *


def solve(s1, s2):
    l1 = re.split('\W+', s1)
    l2 = re.split('\W+', s2)
    if l1[-1] == '':
        l1.pop()
    if l2[-1] == '':
        l2.pop()

    N = len(l1)
    M = len(l2)
    if N == 0 or M == 0:
        return 'Blank!'
    lcs = zeros((N + 1, M + 1), dtype=int)
    for i in range(N - 1, -1, -1):
        for j in range(M - 1, -1, -1):
            lcs[i, j] = lcs[i + 1, j + 1]
            if l1[i] == l2[j]:
                lcs[i, j] += 1
            else:
                lcs[i, j] = max(lcs[i + 1, j], lcs[i, j + 1])
    return 'Length of longest match: %d' % lcs[0, 0]


sys.stdin = open('input.txt')
counter = 1
s1 = s2 = ''
for line in sys.stdin:
    if counter % 2 == 0:
        s2 = line.strip()
        print(solve(s1, s2))
    else:
        s1 = line.strip()
    counter += 1
