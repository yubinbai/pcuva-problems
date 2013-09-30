'''
Created on Jul 19, 2013
@author: Yubin Bai
'''
import sys
import numpypy as np
INF = 1 << 31


def kadane(array):
    # kadane's dynamic programming algorithm
    maxSum = 0.0
    currSum = 0.0
    for a in array:
        currSum = max(a, a + currSum)
        maxSum = max(maxSum, currSum)
    return maxSum


def solve(par):
    N, mat = par
    # construct the sum of each column in side the array
    # so kadane's algorithm can be used in each sub row sum
    for j in range(N):
        for i in range(1, N):
            mat[i, j] += mat[i - 1, j]

    maxSum = -1 * INF
    for i in range(N):
        for j in range(i, N):
            array = [mat[j, k] - mat[i, k] for k in range(N)]
            maxSum = max(maxSum, kadane(array))
    return maxSum


if __name__ == '__main__':
    sys.stdin = open('input.txt', 'r')
    N = int(input())
    mat = []
    while True:
        try:
            mat += map(int, raw_input().split())
        except:
            break
    mat = np.array(mat)
    mat = np.reshape(mat, (N, N))
    print(solve((N, mat)))
