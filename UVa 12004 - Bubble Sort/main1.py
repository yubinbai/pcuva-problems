import sys
from fractions import *

sys.stdin = open('input.txt')
numTest = int(input())
for itertest in range(numTest):
    n = int(input())
    print 'Case %d: %s' % (itertest + 1, Fraction(n * (n - 1), 4))
