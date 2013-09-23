import sys


def dfs(r, c):
    cell = sheet[r][c]
    if cell[0] == '=':
        cells = cell.strip('=').split('+')
        total = 0
        for w in cells:
            col = row = 0
            for char in w:
                if char >= 'A' and char <= 'W':
                    col = col * 26 + ord(char) - ord('A') + 1
                else:
                    row = row * 10 + ord(char) - ord('0')
            col -= 1
            row -= 1
            total += dfs(row, col)
        sheet[r][c] = str(total)
        return total
    else:
        return int(cell)

sys.stdin = open('input.txt')
numTest = int(input())
for itertest in range(numTest):
    col, row = map(int, raw_input().split())
    sheet = []
    for r in range(row):
        sheet.append(raw_input().split())
    for r in range(row):
        for c in range(col):
            dfs(r, c)
    for r in range(row):
        print ' '.join(sheet[r])
