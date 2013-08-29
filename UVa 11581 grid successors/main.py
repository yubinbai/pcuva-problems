import sys
from numpypy import *

sys.stdin = open('input.txt')
numTest = int(input())
for itertest in range(numTest):
    raw_input()
    grid = zeros((3, 3), dtype=byte)
    nextGrid = zeros((3, 3), dtype=byte)
    for i in range(3):
        line = raw_input().strip()
        for j in range(3):
            grid[i, j] = int(line[j])
    counter = -1
    while True:
        for i in range(3):
            for j in range(3):
                d = [(i, j - 1), (i, j + 1), (i - 1, j), (i + 1, j)]
                nextGrid[i, j] = 0
                for i1, j1 in d:
                    if i1 < 3 and i1 >= 0 and j1 < 3 and j1 >= 0:
                        nextGrid[i, j] += grid[i1, j1]
                nextGrid[i, j] %= 2
        grid, nextGrid = nextGrid, grid
        if all(grid == nextGrid):
            break
        else:
            counter += 1
    print counter
