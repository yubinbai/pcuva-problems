import sys


def threeSumClosest(array, target):
    array.sort()
    size = len(array)
    result = [1 << 33, -1, -1, -1]  # a large number
    for first in range(size - 2):
        left = first + 1
        right = size - 1
        while left < right:
            curr = array[first] + array[left] + array[right]
            distance = abs(curr - target)
            if distance < result[0]:
                result = [distance, array[first], array[left], array[right]]
            if curr < target:
                left += 1
            else:
                right -= 1

    return result[1] + result[2] + result[3]


if __name__ == '__main__':
    sys.stdin = open('input.txt')
    while True:
        n = int(input())
        if not n:
            break
        array = []
        for x in xrange(1, n + 1):
            array.append(int(input()))
        array.sort()
        flag = False
        for d in reversed(array):
            if threeSumClosest(array, d) == d:
                print d
                flag = True
                break
        if not flag:
            print 'no solution'
