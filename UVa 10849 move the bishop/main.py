import sys

sys.stdin = open('input.txt')
for _ in range(int(input())):
    raw_input()
    case = int(input())
    n = int(input())
    for _ in range(case):
        r1, c1, r2, c2 = map(int, raw_input().split())
        if (r1 + c1) % 2 != (r2 + c2) % 2 or any([_ > n for _ in [r1, c1, r2, c2]]):
            print 'no move'
        elif (r1, c1) == (r2, c2):
            print 0
        elif abs(r1 - c1) == abs(r2 - c2) or r1 + c1 == r2 + c2:
            print 1
        else:
            print 2
