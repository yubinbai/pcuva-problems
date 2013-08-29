import sys
from collections import Counter

sys.stdin = open('input.txt')
numTest = int(input())
for itertest in range(numTest):
    r, c, m, n = map(int, raw_input().split())
    lines = []
    for i in range(r):
        lines.append(raw_input().strip())
    lines = ''.join(lines)
    counter = Counter(lines).most_common()
    print counter
    maxI, maxSum = 0, 0
    for t in counter:
        if t[1] >= maxI:
            maxSum += t[1]
            maxI = t[1]
    print maxSum * m + (r * c - maxSum) * n
