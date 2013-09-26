import sys
import re
from collections import Counter

sys.stdin = open('input.txt')
n = int(input())
line = []
for i in range(n):
    line += re.findall('[a-zA-Z]', raw_input().strip())
c = Counter(c.upper() for c in line)
for k, v in c.most_common():
    print k, v
