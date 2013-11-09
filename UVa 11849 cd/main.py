import sys

sys.stdin = open('input.txt')
while True:
    m, n = map(int, raw_input().split())
    if not m and not n:
        break
    mA = [int(input()) for _ in range(m)]
    nA = [int(input()) for _ in range(n)]
    i = j = counter = 0
    while i < m:
        if mA[i] == nA[j]:
            counter += 1
            i += 1
            j += 1
        elif mA[i] < nA[j]:
            i += 1
        else:
            j += 1
    print counter
