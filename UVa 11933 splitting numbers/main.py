import sys

sys.stdin = open('input.txt')
while True:
    n = int(input())
    if not n:
        break
    a = b = 0
    flag = True
    for i in range(32):
        if n & (1 << i):
            if flag:
                a |= 1 << i
            else:
                b |= 1 << i
            flag = not flag
    print a, b
