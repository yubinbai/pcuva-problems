import sys

sys.stdin = open('input.txt')
for _ in range(int(input())):
    n, x = map(int, raw_input().split())
    tx = x
    better = -1
    while tx and not (tx & 1):
        better += 1
        tx >>= 1
    if tx:
        better += 1
    nOne = 0
    while tx:
        nOne += 1
        tx &= tx - 1
    if better >= 0:
        print nOne + 1, (1 << n) + 1 - (1 << better)
    else:
        print nOne + 1, 1
