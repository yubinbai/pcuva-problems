import sys
import math


def allFactors(number):
    result = []
    for i in range(1, int(math.sqrt(number)) + 1):
        a, b = divmod(number, i)
        if b == 0:
            if i <= a:
                result.append(i)
                if a != i:
                    result.append(a)
            else:
                break
    return result


def dSigma(n):
    f = allFactors(n)
    return len(f), sum(f)

MAXN = 100005
memo = map(dSigma, range(MAXN))
sys.stdin = open('input.txt')
for _ in range(int(input())):
    a, b, k = map(int, raw_input().split())
    sumD = sumS = 0
    for x in range(a, b + 1):
        if x % k == 0:
            sumD += memo[x][0]
            sumS += memo[x][1]
    print sumD, sumS
