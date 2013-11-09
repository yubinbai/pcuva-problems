import sys

sys.stdin = open('input.txt')
while True:
    a, b, c, d = map(int, raw_input().split())
    if not any([a, b, c, d]):
        break
    if (a, b) >= (c, d):
        c += 24
    print 60 * c + d - 60 * a - b
