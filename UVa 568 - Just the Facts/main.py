import sys

sys.stdin = open('input.txt')
while True:
    try:
        N = int(input())
    except:
        break
    result = 1
    five = 0
    two = 0
    for i in range(1, N + 1):
        i1 = i
        while i1 % 2 == 0:
            two += 1
            i1 //= 2
        while i1 % 5 == 0:
            five += 1
            i1 //= 5
        result *= (i1 % 10)
        result %= 10
    for i in range(two - five):
        result <<= 1
        result %= 10
    print '%9d -> %s' % (N, result)
