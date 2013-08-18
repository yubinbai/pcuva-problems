def modPow(x, y, n):
    if y == 0:
        return 1
    elif y == 1:
        return x % n
    if y % 2 == 1:
        p = modPow(x, y - 1, n)
        return (p * x) % n
    else:
        p = modPow(x, y >> 1, n)
        return (p * p) % n

import sys
sys.stdin = open('input.txt')
numTest = int(input())
for itertest in range(numTest):
    x, y, n = map(int, raw_input().split())
    print(modPow(x, y, n))
