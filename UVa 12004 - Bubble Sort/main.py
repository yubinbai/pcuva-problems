import sys
from fractions import *

sys.stdin = open('input.txt')

# f(n) = f(n-1) + n * (n-1) / 2 / n
results = [Fraction(0, 1)]
for i in range(1, 10001):
    results.append(results[-1] + Fraction(i, 2))
# print results
numTest = int(input())
for itertest in range(numTest):
    print 'Case %d: %s' % (itertest + 1, results[int(input()) - 1])
