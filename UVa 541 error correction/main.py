import sys

sys.stdin = open('input.txt')
while True:
    N = int(input())
    if not N:
        break
    mat = []
    for x in range(N):
        mat.append(map(int, raw_input().split()))
    rows = [sum(mat[i]) for i in range(N)]
    cols = []
    for x in range(N):
        cols.append(sum(mat[i][x] for i in range(N)))
    rowCount = []
    colCount = []
    for i, v in enumerate(rows):
        if v % 2:
            rowCount.append(i + 1)
    for i, v in enumerate(cols):
        if v % 2:
            colCount.append(i + 1)
    if len(rowCount) == 0 and len(colCount) == 0:
        print 'OK'
    elif len(rowCount) == 1 and len(colCount) == 1:
        print 'Change bit (%d, %d)' % (rowCount[0], colCount[0])
    else:
        print 'Corrupt'
