'''
Created on Jul 20, 2013
@author: Yubin Bai
'''
import sys
INF = 1 << 31


def solve(par):
    def dp(side, index):
        if (side, index) in memo:
            return memo[(side, index)]
        if side % 2:
            bottomColor = cubes[index][side - 1]
        else:
            bottomColor = cubes[index][side + 1]

        currMax = 1
        currSide, currP = side, index
        for index1 in range(index + 1, N):
            for i, c in enumerate(cubes[index1]):
                if c == bottomColor:
                    m1 = dp(i, index1) + 1
                    if m1 > currMax:
                        currSide, currP = i, index1
                        currMax = m1

        next[(side, index)] = (currSide, currP)
        memo[(side, index)] = currMax
        return currMax

    N, cubes = par
    memo = {}
    next = {}

    path = []
    currMax = -1
    for i in range(6):
        if dp(i, 0) > currMax:
            side, currMax = i, dp(i, 0)
    idx = 0
    while True:
        path.append((side, idx))
        side, idx = next[(side, idx)]
        if (side, idx) == path[-1]:
            break
    pathStr = []
    side = {0: 'front', 1: 'back', 2: 'left',
            3: 'right', 4: 'top', 5: 'bottom'}
    for p in path:
        pathStr.append('%d %s' % (p[1] + 1, side[p[0]]))

    return '%d\n%s\n' % (currMax, '\n'.join(pathStr))


if __name__ == '__main__':
    sys.stdin = open('input.txt', 'r')

    caseNum = 0
    while True:
        N = int(input())
        if N == 0:
            break
        caseNum += 1
        cubes = []
        for i in range(N):
            cubes.append(map(int, raw_input().split()))
        print('Case #%d\n%s' % (caseNum, solve((N, cubes))))
