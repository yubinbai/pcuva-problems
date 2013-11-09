import sys
import itertools


def gcd(a, b):
    while b:
        a, b = b, a % b
    return a

sys.stdin = open('input.txt')
for _ in range(int(input())):
    A = map(int, raw_input().split())
    print max(gcd(a, b) for a, b in itertools.combinations(A, 2))
