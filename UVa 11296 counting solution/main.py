import sys

sys.stdin = open('input.txt')
while True:
    try:
        n = int(input())
    except:
        break
    x = 1 + (n >> 1)
    print x * (x + 1) / 2
