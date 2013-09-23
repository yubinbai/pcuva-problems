import sys

sys.stdin = open('input.txt')
while True:
    N = int(input())
    if N < 0:
        break
    m, f = 0, 1
    for x in range(N):
        m, f = f + m, m + 1
    print m, f + m
