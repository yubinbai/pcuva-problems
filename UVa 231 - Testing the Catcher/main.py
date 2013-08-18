'''
Created on Jul 20, 2013
@author: Yubin Bai
'''
import sys
INF = 1 << 31


def LDS(array):
    N = len(array)
    longest = [0] * N
    longest[0] = 1
    for i in range(1, N):
        currMax = 1
        for j in range(i):
            if array[i] <= array[j] and longest[j] + 1 > currMax:
                currMax = longest[j] + 1
        longest[i] = currMax
    return max(longest)


def solve(par):
    array = par
    return 'maximum possible interceptions: %d' % LDS(array)


if __name__ == '__main__':
    sys.stdin = open('input.txt', 'r')
    array = []
    while True:
        n = int(input())
        if n == -1:
            print(solve(array))
            array = []
            n1 = int(input())
            if n1 == -1:
                break
            else:
                array.append(n1)
        else:
            array.append(n)
