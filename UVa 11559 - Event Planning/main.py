import sys

sys.stdin = open('input.txt')
INF = 1 << 30
while True:
    result = INF
    try:
        N, B, H, W = map(int, raw_input().split())
    except:
        break
    for i in range(H):
        P = int(input())
        beds = map(int, raw_input().split())
        for b in beds:
            if b >= N and N * P <= B:
                result = min(result, N * P)
    if result != INF:
        print result
    else:
        print 'stay home'
