import sys
import bisect


def fib(n):
    a, b = 0, 1
    while b < n:
        yield b
        a, b = b, a + b
fibArray = list(fib(100000005))
sys.stdin = open('input.txt')
numTest = int(input())
for itertest in range(numTest):
    N = int(input())
    print '%d =' % N,
    idx = bisect.bisect_right(fibArray, N)
    result = []
    for i in reversed(range(1, idx)):
        if N >= fibArray[i]:
            result.append('1')
            N -= fibArray[i]
        else:
            result.append('0')
    print '%s (fib)' % ''.join(result)
