import sys
import bisect

sys.stdin = open('input.txt')


def hasRepeat(n):
    digits = []
    while n:
        n, d = divmod(n, 10)
        if d in digits:
            return False
        digits.append(d)
    return True

allNum = filter(hasRepeat, range(1, 5005))
while True:
    try:
        i, j = map(int, raw_input().split())
    except:
        break
    print bisect.bisect_left(allNum, j + 1) - bisect.bisect_left(allNum, i)
