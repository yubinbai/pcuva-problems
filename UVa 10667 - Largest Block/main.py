import sys
from numpypy import *


def kadane(array, width):
    # kadane's dynamic programming algorithm
    maxL, maxR, maxSum = -1, -1, 0
    currL, currR, currSum = 0, 0, 0
    for i, a in enumerate(array):
        if a != width or currSum + a < a:
            currL, currR, currSum = i + 1, i + 1, 0
        else:
            currR, currSum = i + 1, currSum + a
        if maxSum < currSum:
            maxL, maxR, maxSum = currL, currR, currSum
    return maxL, maxR, maxSum


def solve(par):
    S, B, blocks = par
    mat = ones((S + 1, S + 1), dtype=byte)
    for i in range(S + 1):
        mat[i, 0] = mat[0, i] = 0
    for bloc in blocks:
        i1, j1, i2, j2 = bloc
        for i in range(i1, i2 + 1):
            for j in range(j1, j2 + 1):
                mat[i, j] = 0

    memo = zeros((S + 1, S + 1), dtype=byte)  # store the sum of upperleft
    for j in range(1, S + 1):
        if mat[1, j] == 1:
            memo[1, j] = 1
        for i in range(1, S + 1):
            if mat[i, j] == 1:
                memo[i, j] = 1 + memo[i - 1, j]
            else:
                memo[i, j] = memo[i - 1, j]

    currMax = -1
    for i in range(0, S):
        for j in range(i, S + 1):
            array = []
            for k in range(1, S + 1):
                array.append(memo[j, k] - memo[i, k])
            maxL, maxR, maxSum = kadane(array, j - i)
            if maxSum > currMax:
                currMax = maxSum
                # print(i, maxL, j, maxR, maxSum)
    return currMax


if __name__ == '__main__':
    sys.stdin = open('input.txt', 'r')
    numTests = int(input())
    for itertest in range(numTests):
        S = int(input())
        B = int(input())
        blocks = []
        for i in range(B):
            blocks.append(map(int, raw_input().split()))

        print(solve((S, B, blocks)))
