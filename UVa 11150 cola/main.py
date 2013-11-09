import sys

sys.stdin = open('input.txt')
while True:
    try:
        n = int(input())
    except:
        break
    total = n
    while n >= 3:
        total += (n // 3)
        n = n // 3 + n % 3
    if n == 2:
        total += 1
    print total
