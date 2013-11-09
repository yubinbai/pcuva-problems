import sys


class Elephant(object):

    def __init__(self, w, q, n):
        self.w = w
        self.q = q
        self.n = n

    def __lt__(self, other):
        if self.w < other.w and self.q > other.q:
            return True
        else:
            return False


def longestIncreasing(array):

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
        low, high = 0, len(memo) - 1
        while low < high:
            mid = (low + high) >> 1
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
sys.stdin = open('input.txt')
n = 0
a = []
while True:
    try:
        w, q = map(int, raw_input().split())
    except:
        break
    n += 1
    a.append(Elephant(w, q, n))
N, p = longestIncreasing(a)
print N
for e in p:
    print e.n
