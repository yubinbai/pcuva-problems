import sys

sys.stdin = open('input.txt')
while True:
    n = int(input())
    if not n:
        break
    p = 0
    while 1 << p <= n:
        p += 1
    for i in range(p, 0, -1):
        # print i, pow(n, 1.0 / i)
        if int(pow(n, 1.0 / i)) ** i == n:
            print i
            break
