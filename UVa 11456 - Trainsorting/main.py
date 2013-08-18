'''
Created on Jul 20, 2013
@author: Yubin Bai
'''
import sys
INF = 1 << 31
MAXW = 3005


def longestIncreasing(array):
    """
    return the length of longest longestIncreasing sequence at each position

    O(n log n)

    memo[j] — stores the position k of the
    smallest value X[k] such that there is an increasing subsequence of length j
    ending at X[k] on the range k ≤ i

    """

    memo = [0]
    longest = [0] * len(array)
    longest[0] = 1
    for i in range(1, len(array)):
        # if next one is greater, add into the sequence
        if array[memo[-1]] < array[i]:
            memo.append(i)
            longest[i] = len(memo)
            continue
        # binary search for the best update point
        low = 0
        high = len(memo) - 1
        while low < high:
            mid = (low + high) // 2
            if array[memo[mid]] < array[i]:
                low = mid + 1
            else:
                high = mid
        # update if the new value is smaller
        if array[i] < array[memo[low]]:
            memo[low] = i
        longest[i] = len(memo)

    return longest


def longestDecreasing(array):
    """
    return the length of longest longestDecreasing sequence at each position

    O(n log n)

    memo[j] — stores the position k of the
    smallest value X[k] such that there is an increasing subsequence of length j
    ending at X[k] on the range k ≤ i

    """

    memo = [0]
    longest = [0] * len(array)
    longest[0] = 1
    for i in range(1, len(array)):
        # if next one is smaller, add into the sequence
        if array[memo[-1]] > array[i]:
            memo.append(i)
            longest[i] = len(memo)
            continue
        # binary search for the best update point
        low = 0
        high = len(memo) - 1
        while low < high:
            mid = (low + high) // 2
            if array[memo[mid]] > array[i]:
                low = mid + 1
            else:
                high = mid
        # update if the new value is bigger
        if array[i] > array[memo[low]]:
            memo[low] = i
        longest[i] = len(memo)

    return longest


def solve(par):
    N, cars = par
    inc = longestIncreasing(cars)
    dec = longestDecreasing(cars)

    return max(inc[i] + dec[i] - 1 for i in range(N))


if __name__ == '__main__':
    sys.stdin = open('input.txt', 'r')
    numTest = int(input())
    for itertest in range(numTest):
        N = int(input())
        if N == 0:
            break
        cars = []
        for i in range(N):
            cars.append(int(input()))
        print(solve((N, cars)))
