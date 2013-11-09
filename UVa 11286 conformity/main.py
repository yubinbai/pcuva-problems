import sys
from collections import Counter

sys.stdin = open('input.txt')
while True:
    n = int(input())
    if not n:
        break
    comb = []
    for _ in range(n):
        comb.append(tuple(sorted(map(int, raw_input().split()))))
    kv = Counter(comb).most_common()
    maxV = kv[0][1]
    total = 0
    for k, v in kv:
        if v == maxV:
            total += maxV
        else:
            break
    print total
