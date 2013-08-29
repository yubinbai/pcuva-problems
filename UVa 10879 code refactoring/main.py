from math import sqrt
def allFactors(number):
    result = []
    for i in range(2, int(sqrt(number)) + 1):
        a, b = divmod(number, i)
        if b == 0 and i <= a:
            if a != i:
                result.append(i)
                result.append(a)
                if len(result) == 4:
                    break
    return result

import sys

sys.stdin = open('input.txt')
numTest = int(input())
for itertest in range(numTest):
    N = int(input())
    result = allFactors(N)
    print 'Case #%d %s' % (itertest+1, str(result))
