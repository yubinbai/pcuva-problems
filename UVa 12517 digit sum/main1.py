import sys


def sumofDigit(n, p10, after):
    if n == 0:
        return 0
    m = n % 10
    # each round get the last digit
    # p10 keeps power of 10
    # after keeps the number after the current number, i.e. originalN % p10
    return n / 10 * 45 * p10 + m * after + m * (m - 1) / 2 * p10 +\
        sumofDigit(n / 10, p10 * 10, after + m * p10)

sys.stdin = open('input.txt')
while True:
    a, b = map(int, raw_input().split())
    if not a and not b:
        break
    print sumofDigit(b, 1, 1) - sumofDigit(a - 1, 1, 1)
