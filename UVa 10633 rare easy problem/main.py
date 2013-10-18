import sys

sys.stdin = open('input.txt')
while True:
    n = int(input())
    if not n:
        break
    x = n + n // 9
    if x % 9 == 0:
        print x
    else:
        print x - 1, x
