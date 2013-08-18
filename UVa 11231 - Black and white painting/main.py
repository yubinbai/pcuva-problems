import sys

sys.stdin = open('input.txt')
for line in sys.stdin:
    N, M, C = map(int, line.split())
    if N == 0:
        break
    N -= 7
    M -= 7
    if (N % 2 and M % 2) and C:
        print N * M // 2 + 1
    else:
        print N * M // 2
