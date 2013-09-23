import sys
import re
from collections import Counter

sys.stdin = open('input.txt')
numTest = int(input())
for x in range(numTest):
    raw_input()
    line1 = raw_input().strip()
    line2 = raw_input().strip()
    c1 = Counter(re.findall('[a-zA-Z]', line1))
    c2 = Counter(re.findall('[a-zA-Z]', line2))
    freq1 = sorted([(v, k) for k, v in c1.items()])
    freq2 = sorted([(v, k) for k, v in c2.items()])
    d = dict((freq2[i][1], freq1[i][1]) for i in range(len(freq1)))
    result = []
    for c in line2:
        try:
            result.append(d[c])
        except:
            result.append(c)
    print ''.join(result)
