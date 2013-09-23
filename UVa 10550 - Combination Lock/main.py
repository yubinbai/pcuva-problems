import sys

sys.stdin = open('input.txt')
while True:
    a, b, c, d = map(int, raw_input().split())
    if sum([a, b, c, d]) == 0:
        break
    print 360 * 2 + (a - b + 40) % 40 * 9 + 360 + \
        (c - b + 40) % 40 * 9 + (c - d + 40) % 40 * 9
