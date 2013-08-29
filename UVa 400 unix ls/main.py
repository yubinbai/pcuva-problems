import sys

sys.stdin = open('input.txt')
while True:
    try:
        N = int(input())
    except:
        break
    lines = []
    for i in range(N):
        lines.append(raw_input().strip())
    lines.sort()
    L = max(len(s) for s in lines)
    cols = max(1, 60 // (L + 2))
    # print cols
    if cols == 1:
        formatStr = '%-60s'
    else:
        formatStr = ''
        width = L + 2
        for i in range(cols - 1):
            formatStr += '%%-%ds' % width
        formatStr += '%%-%ds' % L
    # print formatStr
    table = []
    if N % cols:
        row = N // cols + 1
    else:
        row = N // cols
    for i in range(row):
        table.append([])
    # print table
    for i, w in enumerate(lines):
        table[i % row].append(w)
    for r in reversed(table):
        if len(r) < len(table[0]):
            r.append('')
    print '-' * 60
    for r in range(row):
        print formatStr % tuple(table[r])
