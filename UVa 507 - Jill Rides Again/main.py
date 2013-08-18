import sys
from numpypy import *
INF = 1 << 31


def kadane(array):
    '''
    kadane's dynamic programming algorithm
    '''
    maxL, maxR, maxSum = -1, -1, 0
    currL, currR, currSum = 0, 0, 0
    for i, a in enumerate(array):
        if currSum < 0:
            currL, currR, currSum = i, i + 1, a
        else:
            currR, currSum = i + 1, currSum + a
        if maxSum < currSum or \
                (maxSum == currSum and currR - currL > maxR - maxL):
            maxL, maxR, maxSum = currL, currR, currSum
    return maxL, maxR, maxSum


def solve(par):
    test, N, array = par
    maxL, maxR, maxSum = kadane(array)
    if maxSum > 0:
        return 'The nicest part of route %d is between stops %d and %d'\
            % (test, maxL + 1, maxR + 1)
    else:
        return 'Route %d has no nice parts' % test


if __name__ == '__main__':
    sys.stdin = open('input.txt', 'r')
    numTests = int(input())
    for itertest in range(numTests):
        N = int(input())
        array = []
        for i in range(N - 1):
            array.append(int(input()))
        print(solve((itertest + 1, N, array)))
