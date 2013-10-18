import sys

sys.stdin = open('input.txt')
while True:
    try:
        n = int(input())
    except:
        break
    print 2 + n * (n - 1)
