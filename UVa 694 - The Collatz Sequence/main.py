import sys

sys.stdin = open('input.txt')
while True:
    A, L = map(int, raw_input().split())
    if A == -1 and L == -1:
        break
    seq = 1
    while A != 1 and A <= L:
        if A % 2:
            A = 3 * A + 1
        else:
            A /= 2
        seq += 1
    print seq