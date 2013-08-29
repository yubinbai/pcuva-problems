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

    if N % cols:
        rows = N // cols + 1
    else:
        rows = N // cols
    diff = rows * cols - len(lines)
    lines.extend([''] * diff)
    print '-' * 60
    for r in range(rows):
        line = []
        for c in range(cols - 1):
            line.append('%%-%ds' % (L + 2) % lines[c * rows + r])
        line.append('%%-%ds' % (L + 2) % lines[(cols - 1) * rows + r])
        print ''.join(line)
