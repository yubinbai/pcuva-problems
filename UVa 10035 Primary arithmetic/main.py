import sys
sys.stdin = open('input.txt')
while True:
    a, b = map(int, raw_input().split())
    if a == 0 and b == 0:
        break
    sumC = 0
    c = 0
    while a and b:
        c = a % 10 + b % 10 + c
        c = int(c > 9)
        sumC += c
        a //= 10
        b //= 10
    print '%d' % sumC
