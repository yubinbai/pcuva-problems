import sys

sys.stdin = open('input.txt')
numTest = int(input())
print 'Lumberjacks:'
for itertest in range(numTest):
    A = map(int, raw_input().split())
    flag = True
    if A[0] > A[-1]:
        for i in range(1, 10):
            if A[i] > A[i - 1]:
                flag = False
                break
    else:
        for i in range(1, 10):
            if A[i] < A[i - 1]:
                flag = False
                break
    if flag:
        print 'Ordered'
    else:
        print 'Unordered'
