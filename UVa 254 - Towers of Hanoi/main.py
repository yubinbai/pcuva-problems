import sys

sys.stdin = open('input.txt')
while True:
    N, M = map(int, raw_input().split())
    if not N and not M:
        break
    t1 = t2 = t3 = 0
    mLen = len(bin(M)) - 2
    for x in range(mLen):
        if M & (1 << x):
            t3 += 1
            t1, t2 = t2, t1
        else:
            t1 += 1
            t2, t3 = t3, t2
    left = N - mLen
    if left & 1:
        t2, t3 = t3, t2
    t1 += left
    if N & 1:
        print t1, t3, t2
    else:
        print t1, t2, t3
