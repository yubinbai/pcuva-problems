import sys
from bisect import bisect_left
MAXN = 100000


def init():
    for i in range(1, 6):
        for j in range(10 ** (i - 1), 10 ** i):
            num[j] = num[j - 1]
            tmp = (j - 10 ** (i - 1) + 1) * i
            for k in range(1, i):
                tmp += (10 ** k - 10 ** (k - 1)) * k
            num[j] += tmp


def solve():
    pos = bisect_left(num, n)
    count = n - num[pos - 1]
    total = 0
    for j in range(1, pos + 1):
        tmp_j = j
        nLen = len(str(tmp_j))
        for k in reversed(range(nLen)):
            ans = tmp_j / 10 ** k  # get each digit of j
            total += 1
            if (total == count):
                print '%d' % ans
                return
            tmp = 10 ** (k)
            tmp_j %= tmp


sys.stdin = open('input.txt')
num = [0] * MAXN
n = 0
init()
numTest = int(input())
for itertest in range(numTest):
    n = int(input())
    solve()
