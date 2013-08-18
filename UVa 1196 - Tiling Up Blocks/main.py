'''
Created on Jul 20, 2013
@author: Yubin Bai
'''
import sys
INF = 1 << 31
MAXW = 3005


def longestIncreasing(array):
    """
    return N (length), path(list) as a tuple describing the subsequence

    O(n log n)

    memo[j] — stores the position k of the
    smallest value X[k] such that there is an increasing subsequence of length j
    ending at X[k] on the range k ≤ i

    """

    memo = [0]
    for i in range(1, len(array)):
        # if next one is greater, add into the sequence
        if array[memo[-1]][0] <= array[i][0] and \
                array[memo[-1]][1] <= array[i][1]:
            memo.append(i)
            continue
        # binary search for the best update point
        low = 0
        high = len(memo) - 1
        while low < high:
            mid = (low + high) // 2
            if array[memo[mid]][0] <= array[i][0] and \
                    array[memo[mid]][1] <= array[i][1]:
                low = mid + 1
            else:
                high = mid
        # update if the new value is smaller
        if array[memo[low]][0] > array[i][0] and \
                array[memo[low]][1] > array[i][1]:
            memo[low] = i

    return len(memo)


def solve(par):
    N, tiles = par
    tiles.sort()
    return longestIncreasing(tiles)


if __name__ == '__main__':
    sys.stdin = open('input.txt', 'r')

    while True:
        N = int(input())
        if N == 0:
            print('*')
            break
        tiles = []
        for i in range(N):
            tiles.append(tuple(map(int, raw_input().split())))
        print(solve((N, tiles)))
