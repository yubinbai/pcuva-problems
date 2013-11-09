import sys

sys.stdin = open('input.txt')
while True:
    a, b, c, d = map(int, raw_input().split())
    if not any([a, b, c, d]):
        break
    if (a, b) == (c, d):
        print 0
    elif a == c or b == d or a + b == c + d or abs(a - b) == abs(c - d):
        print 1
    else:
        print 2
