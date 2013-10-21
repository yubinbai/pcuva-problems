import sys

sys.stdin = open('input.txt')
while True:
    n = int(input())
    if not n:
        break
    deg = 0
    x = n
    while not x % 9:
        x = sum(map(int, str(x)))
        deg += 1
        if x == 9:
            break
    if deg:
        print '%d is a multiple of 9 and has 9-degree %d.' % (n, deg)
    else:
        print '%d is not a multiple of 9.' % n
