import sys

sys.stdin = open('input.txt')
while True:
    a, b, c, d, e = map(int, raw_input().split())
    if not any([a, b, c, d, e]):
        break
    print a * b * c * d ** 2 * e ** 2
