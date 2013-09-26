import sys
from collections import Counter

sys.stdin = open('input.txt')
numTest = int(input())
for x in range(numTest):
    n = raw_input().strip()
    b1 = Counter(bin(int(n)))['1']
    b2 = Counter(bin(int(n, base=16)))['1']
    print b1, b2
