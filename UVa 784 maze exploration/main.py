import sys


def fill(x, y):
    stack = [(x, y)]
    while stack:
        x, y = stack.pop()
        dire = [(x - 1, y), (x + 1, y), (x, y + 1), (x, y - 1)]
        for x1, y1 in dire:
            if maze[x1][y1] == ' ':
                maze[x1][y1] = '#'
                stack.append((x1, y1))

sys.stdin = open('input.txt')
numTest = int(input())
for itertest in range(numTest):
    maze = []
    while True:
        line = raw_input().strip()
        if line[0] == '_':
            break
        idx = line.find('*')
        if idx != -1:
            startX, startY = len(maze), idx
        line = line.replace('*', '#')
        maze.append(list(line))

    print 'Case #%d' % (itertest + 1)
    fill(startX, startY)
    for line in maze:
        print ''.join(line)
