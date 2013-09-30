import sys
import bisect
import re

fibs = [1]
a, b = 1, 1
while b < 1 << 32:
    a, b = b, a + b
    fibs.append(b)

sys.stdin = open('input.txt')
numTest = int(input())
for itertest in range(numTest):
    N = int(input())
    seq = map(int, raw_input().split())
    line = re.findall('[A-Z]', raw_input().strip())
    result = [' '] * 100
    for i, c in enumerate(line):
        idx = bisect.bisect_left(fibs, seq[i])
        result[idx] = c
    print ''.join(result).strip(' ')
