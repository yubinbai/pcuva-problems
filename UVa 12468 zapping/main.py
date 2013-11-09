import sys

sys.stdin = open('input.txt')
while True:
    a, b = map(int, raw_input().split())
    if a > b:
        a, b = b, a
    if a == -1 and b == -1:
        break
    print min(b - a, a + 100 - b)
