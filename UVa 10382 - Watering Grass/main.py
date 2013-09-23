import sys
from math import sqrt

sys.stdin = open('input.txt')
while True:
    try:
        N, L, W = map(int, raw_input().split())
    except:
        break
    A = []
    for x in range(N):
        p, r = map(int, raw_input().split())
        if r * 2 < W:
            continue
        d = sqrt(r ** 2 - (W / 2.0) ** 2)
        left, right = max(0, p - d), min(L, p + d)
        A.append((left, right))
    A.sort()
    left = A[0][0]
    right = A[0][1]
    count = 1
    for i in range(1, N):
        if A[i][0] > right:
            break
        elif A[i][0] <= left and A[i][1] > right:
            right = A[i][1]
        elif A[i][0] > left and A[i][1] > right:
            left = right
            right = A[i][1]
            count += 1
    if right != L:
        count = -1
    print count
