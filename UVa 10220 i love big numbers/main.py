import sys

sys.stdin = open('input.txt')
while True:
    try:
        n = int(input())
    except:
        break
    total = 1
    for i in range(2, n + 1):
        total *= i
    print sum(map(int, str(total)))
