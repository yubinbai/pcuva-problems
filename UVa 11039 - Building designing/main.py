import sys

sys.stdin = open('input.txt')
numTest = int(input())
for itertest in range(numTest):
    N = int(input())
    A = []
    for i in range(N):
        A.append(int(input()))
    A.sort()
    low = 0
    high = N - 1
    if abs(A[0]) > abs(A[-1]):
        leftFirst = True
        curr = abs(A[0])
    else:
        leftFirst = False
        curr = abs(A[-1])
    print A
    counter = 0
    while low < high:
        if leftFirst:
            while abs(A[low]) > curr and A[low] < 0:
                low += 1
            if A[low] < 0:
                curr = abs(A[low])
                low += 1
                leftFirst = False
            else:
                break
        else:
            while abs(A[high]) > curr and A[high] > 0:
                high -= 1
            if A[high] > 0:
                curr = abs(A[high])
                high -= 1
                leftFirst = True
            else:
                break
        counter += 1
    print counter
