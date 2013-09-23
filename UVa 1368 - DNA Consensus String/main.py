import sys
from collections import Counter

sys.stdin = open('input.txt')
numTest = int(input())
for itertest in range(numTest):
    N, L = map(int, raw_input().split())
    allStr = []
    for i in range(N):
        allStr.append(raw_input().strip())
    result = []
    dist = 0
    for i in range(L):
        c = Counter(allStr[j][i] for j in range(N)).most_common(1)
        dist += N - c[0][1]
        result.append(c[0][0])
    print ''.join(result)
    print dist
