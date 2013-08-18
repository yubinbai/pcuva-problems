from itertools import combinations
import sys

sys.stdin = open('input.txt')
numTest = int(input())
for itertest in range(numTest):
    P = int(input())
    N = int(input())
    symbols = []
    for i in range(N):
        line = raw_input().strip().split()
        symbols.append(int(''.join(line), base=2))
    bits = list(range(0, P))
    for result in range(1, P + 1):
        for comb in combinations(bits, result):
            visited = [False] * (1 << P)
            mask = 0
            for c in comb:
                mask |= (1 << c)
            found = True
            for s in symbols:
                if visited[s & mask]:
                    found = False
                else:
                    visited[s & mask] = True
            if found:
                break
        if found:
            print result
            break
