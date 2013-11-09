import math
import sys


def symM(matrix, n):
    flag = True

    for x in range(n & 1 + n >> 1):
        for y in range(n):
            flag &= (matrix[x][y] == matrix[n - 1 - x][n - 1 - y])
            if not flag:
                break
        if not flag:
            break
    return flag

sys.stdin = open('input.txt')
for case in range(1, 1 + int(input())):
    n = int(raw_input().strip().rpartition('=')[2])
    mat = []
    for x in xrange(1, n + 1):
        mat.append(map(int, raw_input().split()))
    if symM(mat, n):
        print 'Test #%d: Symmetric.' % case
    else:
        print 'Test #%d: Non-symmetric.' % case
