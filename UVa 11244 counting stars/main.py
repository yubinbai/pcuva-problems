import sys

sys.stdin = open('input.txt')
while True:
    n, m = map(int, raw_input().split())
    if not n and not m:
        break
    mat = []
    for _ in range(n):
        mat += [map(lambda c:c == '*', raw_input().strip())]

    def dfs(i, j):
        mat[i][j] = False
        d = [(i - 1, j - 1), (i - 1, j), (i - 1, j + 1), (i, j - 1),
             (i, j + 1), (i + 1, j - 1), (i + 1, j), (i + 1, j + 1)]
        flag = False
        for a, b in d:
            if a >= 0 and a < n and b >= 0 and b < m and mat[a][b]:
                flag = True
                dfs(a, b)
        return flag

    counter = 0
    for i in range(n):
        for j in range(m):
            if mat[i][j] and not dfs(i, j):
                counter += 1
    print counter
