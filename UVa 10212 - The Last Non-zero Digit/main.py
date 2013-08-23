import sys

sys.stdin = open('input.txt')
while True:
    try:
        N, M = map(int, raw_input().split())
    except:
        break

    result = 1
    pow2 = 0
    pow5 = 0
    for n in range(N, N - M, -1):
        x = n
        while not (x & 1):
            x >>= 1
            pow2 += 1
        while not (x % 5):
            x //= 5
            pow5 += 1
        result *= x
        result %= 10
    if pow2 > pow5:
        result *= pow(2, pow2 - pow5, 10)
    elif pow5 < pow2:
        result *= pow(5, pow5 - pow2, 10)

    print result % 10
