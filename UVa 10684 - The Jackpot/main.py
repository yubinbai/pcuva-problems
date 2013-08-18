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
    N, array = par
    maxL, maxR, maxSum = kadane(array)
    if maxSum > 0:
        return 'The maximum winning streak is %d.'\
            % (maxSum)
    else:
        return 'Losing streak.'


if __name__ == '__main__':
    sys.stdin = open('input.txt', 'r')
    while True:
        N = int(input())
        if N == 0:
            break
        array = []
        while len(array) < N:
            array.extend(map(int, raw_input().split()))
        print(solve((N, array)))
