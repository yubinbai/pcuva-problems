import sys


sys.stdin = open('input.txt')
while True:
    n = int(input())
    if not n:
        break
    counter = 0
    for i in range(1 << n):
        x = i
        while x:
            if x & 7 == 7:
                counter += 1
                break
            else:
                x >>= 1
    print counter
