import sys
from bisect import bisect_right


def fib(n):
    a, b = 0, 1
    for i in range(n):
        a, b = b, a + b
        yield b

fibArray = list(fib(200))
sys.stdin = open('input.txt')
while True:
    n1 = raw_input().strip()
    n2 = raw_input().strip()
    n1 = n1[::-1]
    n2 = n2[::-1]
    n1 = sum(fibArray[i] for i in range(len(n1)) if n1[i] == '1')
    n2 = sum(fibArray[i] for i in range(len(n2)) if n2[i] == '1')
    n = n1 + n2
    idx = bisect_right(fibArray, n)
    result = []
    while idx >= 0:
        if n >= fibArray[idx]:
            result.append('1')
            n -= fibArray[idx]
        else:
            result.append('0')
        idx -= 1
    print ''.join(result).lstrip('0')
    print
    try:
        raw_input()
    except:
        break
