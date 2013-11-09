import sys

sys.stdin = open('input.txt')
case = 0
while True:
    n = int(input())
    case += 1
    if not n:
        break
    total = 0
    for i in range(1, n // 3):
        if i & 1:
            total += (n - 3 * i) >> 1
        else:
            total += (n - 3 * i) >> 1
            total -= 1
    print 'Case %d: %d' % (case, total)
