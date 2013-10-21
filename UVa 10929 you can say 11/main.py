import sys

sys.stdin = open('input.txt')
while True:
    s = raw_input().strip()
    if s == '0':
        break
    n = map(int, s)
    total = 0
    for i, d in enumerate(n):
        total += d * (-1) ** i
    if total % 11:
        print '%s is not a multiple of 11.' % s
    else:
        print '%s is a multiple of 11.' % s
