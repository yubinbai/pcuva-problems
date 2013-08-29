import sys
from collections import Counter

sys.stdin = open('input.txt')
while True:
    N = int(input())
    if N == 0:
        break
    ans = map(int, raw_input().split())
    guesses = []
    while True:
        guesses.append(map(int, raw_input().split()))
        if guesses[-1] == [0] * N:
            guesses.pop()
            break
    ansCounter = Counter(ans)
    print 'Game:'
    for g in guesses:
        strong = 0
        for i in range(N):
            if g[i] == ans[i]:
                strong += 1
        gCounter = Counter(g)
        weak = 0
        for c in ansCounter:
            try:
                weak += min(ansCounter[c], gCounter[c])
            except:
                pass
        weak -= strong
        print '(%d, %d)' % (strong, weak)
