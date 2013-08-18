'''
Created on Jul 26, 2013
@author: Yubin Bai
'''
import sys
INF = 1 << 31


def solve(par):
    N, M, Q, mat, query = par
    result = []
    for q in query:
        c = mat[q[0]][q[1]]
        size = 1
        finished = False
        while not finished:
            sStr = c * size
            if q[0] - size // 2 >= 0 and q[0] + size // 2 < N \
                    and q[1] - size // 2 >= 0 and q[1] + size // 2:
                for i in range(q[0] - size // 2, q[0] + size // 2 + 1):
                    if sStr != mat[i][q[1] - size // 2:q[1] + size // 2 + 1]:
                        finished = True
                        size -= 2
                        break
                size += 2
            else:
                break
        result.append(str(size - 2))
    return '\n'.join(result)


if __name__ == '__main__':
    sys.stdin = open('input.txt', 'r')
    numTest = int(input())
    for itertest in range(numTest):
        N, M, Q = map(int, raw_input().split())
        mat = []
        for i in range(N):
            mat.append(raw_input().strip())
        query = []
        for i in range(Q):
            query.append(map(int, raw_input().split()))
        print(solve((N, M, Q, mat, query)))
