'''
Created on Jul 20, 2013
@author: Yubin Bai
'''
import sys
INF = 1 << 31


def longestIncreasing(array):
    '''
    return N (length), path(list) as a tuple describing the subsequence

    O(n log n)

    memo[j] — stores the position k of the smallest value X[k] such that
    there is an increasing subsequence of length j ending at X[k] on the
    range k ≤ i
    prev[k]  — stores the position of the predecessor of X[k] in the
    longest increasing subsequence ending at X[k].
    '''

    memo = [0]
    prev = [0] * len(array)
    prev[0] = -1
    for i in range(1, len(array)):
        # if next one is greater, add into the sequence
        if array[memo[-1]] < array[i]:
            prev[i] = memo[-1]
            memo.append(i)
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
            if low > 0:
                prev[i] = memo[low - 1]
            memo[low] = i

    path = []
    p = memo[-1]
    N = len(memo)
    for i in range(N):
        path.append(array[p])
        p = prev[p]
    path.reverse()
    return N, path


def solve(par):
    array = par
    N, path = longestIncreasing(array)
    return 'Max hits: %d\n%s' % (N, '\n'.join(str(e) for e in path))


if __name__ == '__main__':
    sys.stdin = open('input.txt', 'r')
    numTests = int(input())
    for i in range(numTests):
        raw_input()
        array = []
        while True:
            try:
                array.append(int(input()))
            except:
                break
    print(solve(array))
