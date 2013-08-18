import sys


def eightQueen():
    path = []
    colOccupied = [False] * 8
    iPlusJ = {}
    iMinusJ = {}
    for i in range(8):
        for j in range(8):
            iPlusJ[i + j] = False
            iMinusJ[i - j] = False
    result = []

    def backtrack(i):
        if i == 8:
            result.append(list(path))
        for j in range(8):
            if not colOccupied[j] and not iPlusJ[i + j] and not iMinusJ[i - j]:
                path.append(j)
                colOccupied[j] = iPlusJ[i + j] = iMinusJ[i - j] = True
                backtrack(i + 1)
                path.pop()
                colOccupied[j] = iPlusJ[i + j] = iMinusJ[i - j] = False
    backtrack(0)
    return result

sys.stdin = open('input.txt')
solutions = eightQueen()
numTest = int(input())
for itertest in range(numTest):
    board = []
    for i in range(8):
        board.append(map(int, raw_input().split()))
    maxR = 0
    for s in solutions:
        currR = sum(board[i][s[i]] for i in range(8))
        maxR = max(maxR, currR)
    print '%5d' % maxR
