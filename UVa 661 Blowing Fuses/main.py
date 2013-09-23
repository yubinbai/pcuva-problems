import sys

sys.stdin = open('input.txt')
iterTest = 0
while True:
    n, m, c = map(int, raw_input().split())
    iterTest += 1
    if not n and not m and not c:
        break
    items = []
    for x in range(n):
        items.append(int(input()))
    isOn = [False] * n
    maxPow = 0
    for op in range(m):
        a = int(input())
        isOn[a - 1] = not isOn[a - 1]
        p = sum(items[i] for i in range(n) if isOn[i])
        maxPow = max(p, maxPow)
    print 'Sequence %d' % iterTest
    if maxPow > c:
        print 'Fuse was blown.'
    else:
        print 'Fuse was not blown.'
        print 'Maximal power consumption was %d amperes.' % maxPow
