import sys

sys.stdin = open('input.txt')
while True:
    try:
        M, N = map(int, raw_input().split())
    except:
        break
    if M > N:
        M, N = N, M
    print N - 1 + N * (M - 1)
