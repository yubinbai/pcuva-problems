import sys

sys.stdin = open('input.txt')
while True:
    N = int(input())
    if N == 0:
        break
    maxL = 0
    maxI = -1
    for i in range(N):
        x, y = map(int, raw_input().split())
        if x > y:
            x, y = y, x
        if 4 * x <= y:
            if maxL < x:
                maxL, maxI = x, i
        else:
            if maxL < x // 2:
                maxL, maxI = x // 2, i
    print maxI + 1
