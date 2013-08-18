import sys
from numpypy import *
INF = 1 << 31


def kadane(array):
    '''
    kadane's dynamic programming algorithm
    get the max sum with in a certain span
    '''
    maxL, maxR, maxSum = -1, -1, 0
    currL, currR, currSum = 0, 0, 0
    for i, a in enumerate(array):
        if currSum < 0:
            currL, currR, currSum = i, i + 1, a
        else:
            currR, currSum = i + 1, currSum + a
        if maxSum < currSum:
            maxL, maxR, maxSum = currL, currR - 1, currSum
    return maxL, maxR, maxSum


def solve(par):
    N, mat = par
    matrix = zeros((N * 2, N * 2), dtype=byte)

    start = [(0, 0), (N, 0), (0, N), (N, N)]
    for sI, sJ in start:
        for i in range(N):
            for j in range(N):
                matrix[i + sI, j + sJ] = mat[i][j]
    # print matrix
    memo = zeros((2 * N + 1, 2 * N + 1), dtype=int32)
                 # store the sum of upper col
    for j in range(1, 2 * N + 1):
        for i in range(1, 2 * N + 1):
            memo[i, j] = matrix[i - 1, j - 1] + memo[i - 1, j]
    # print memo
    currMax = 0
    for i in range(0, N + 1):
        for j in range(i + 1, i + N + 1):
            for left in range(1, N + 1):
                array = []
                for k in range(left, left + N):
                    array.append(memo[j, k] - memo[i, k])
                maxL, maxR, maxSum = kadane(array)
                if maxSum > currMax:
                    currMax = maxSum
                    print(i + 1, j, maxL + left, maxR + left, maxSum)
    return currMax


if __name__ == '__main__':
    sys.stdin = open('input.txt', 'r')
    numTests = int(input())
    for itertest in range(numTests):
        N = int(input())
        mat = []
        for i in range(N):
            mat.append(map(int, raw_input().split()))

        print(solve((N, mat)))
