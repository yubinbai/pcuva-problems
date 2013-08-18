'''
Created on Jul 20, 2013
@author: Yubin Bai
'''
import sys
INF = 1 << 31


def solve(par):
    def longestIncreasing():
        memo = [0] * N
        memo[0] = width[0]
        for i in range(1, len(height)):
            maxW = 0
            for j in range(i):
                if height[i] > height[j] and maxW < memo[j]:
                    maxW = memo[j]
            memo[i] = width[i] + maxW
        return max(memo)

    def longestDecreasing():
        memo = [0] * N
        memo[0] = width[0]
        for i in range(1, len(height)):
            maxW = 0
            for j in range(i):
                if height[i] < height[j] and maxW < memo[j]:
                    maxW = memo[j]
            memo[i] = width[i] + maxW
        return max(memo)

    N, height, width = par
    a = longestIncreasing()
    b = longestDecreasing()
    if a >= b:
        return 'Increasing (%d). Decreasing (%d).' % (a, b)
    else:
        return 'Decreasing (%d). Increasing (%d).' % (b, a)


if __name__ == '__main__':
    sys.stdin = open('input.txt', 'r')
    numTest = int(input())
    for itertest in range(numTest):
        N = int(input())
        height = map(int, raw_input().split())
        width = map(int, raw_input().split())
        print(solve((N, height, width)))
