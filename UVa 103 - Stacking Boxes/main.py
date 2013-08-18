'''
Created on Jul 20, 2013
@author: Yubin Bai
'''
import sys
INF = 1 << 31


def aContainsB(a, b):
    for i in range(D):
        if a[i] < b[i]:
            return False
    return True


def solve(par):
    N, D, array = par
    for i, row in enumerate(array):
        row.sort()
        row.append(i + 1)
    array.sort()
    # longest increasing subsequence
    longest = [0] * N
    prev = [0] * N
    longest[0] = 1
    prev[0] = 0
    for i in range(1, N):
        idx, currMax = i, 1
        for j in range(i):
            if aContainsB(array[i], array[j]) and longest[j] + 1 > currMax:
                idx = j
                currMax = longest[j] + 1
        prev[i] = idx
        longest[i] = currMax
    # restore the solution
    idx, currMax = 0, 1
    for i, l in enumerate(longest):
        if l > currMax:
            idx, currMax = i, l
    path = []
    while True:
        path.append(array[idx][-1])
        if prev[idx] == idx:
            break
        idx = prev[idx]
    path.reverse()
    return '%d\n%s' % (currMax, ' '.join(str(e) for e in path))


if __name__ == '__main__':
    sys.stdin = open('input.txt', 'r')
    while True:
        try:
            N, D = map(int, raw_input().split())
        except:
            break
        array = []
        for i in range(N):
            array.append(map(int, raw_input().split()))
        print(solve((N, D, array)))
