import sys

sys.stdin = open('input.txt')
numTest = int(input())
for itertest in range(numTest):
    S, A, F = map(int, raw_input().split())
    streets = []
    aves = []
    for i in range(F):
        s, a = map(int, raw_input().split())
        streets.append(s)
        aves.append(a)
    streets.sort()
    aves.sort()
    if F % 2 == 0:
        print '(Street %d, Avenue %d)' %\
            ((streets[F // 2 - 1] + streets[F // 2])
             >> 1, (aves[F // 2 - 1] + aves[F // 2]) >> 1)
    else:
        print '(Street %d, Avenue %d)' %\
            (streets[F // 2], aves[F // 2])
