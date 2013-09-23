'''
Created on Jul 7, 2013

@author: Yubin Bai

All rights reserved.

use dfs as bicoloring method, bfs is also viable

The main idea is to assign to each vertex the color that differs from the color
of its parent in the depth-first search tree, assigning colors in a preorder
traversal of the depth-first-search tree. This will necessarily provide a two-
coloring of the spanning tree consisting of the edges connecting vertices to
their parents, but it may not properly color some of the non-tree edges. In a
depth-first search tree, one of the two endpoints of every non-tree edge is an
ancestor of the other endpoint, and when the depth first search discovers an
edge of this type it should check that these two vertices have different colors.
If they do not, then the path in the tree from ancestor to descendant, together
with the miscolored edge, form an odd cycle, which is returned from the
algorithm together with the result that the graph is not bipartite.

'''

import time
from multiprocessing.pool import Pool
from collections import Counter
from itertools import combinations
parallelSolve = False
INF = 1 << 31
WHITE = 1
BLACK = 0


def solve(par):

    def dfs(e, c):
        color[e] = c
        for i, j in combinations(enemies[e], 2):
            if i in enemies[j] or j in enemies[i]:
                graphError[0] = True

        for i in enemies[e]:
            if color[i] != None:
                continue
            if c == WHITE:
                dfs(i, BLACK)
            else:
                dfs(i, WHITE)

    N, enemies = par
    color = [None] * N
    graphError = [False]
    for row in enemies:
        for j in range(len(row)):
            row[j] -= 1

    for i in range(N):
        if color[i] == None:
            dfs(i, WHITE)

    counter = Counter(color)
    if graphError[0]:
        return 0
    return max(counter.values())


class Solver:

    def getInput(self):
        self.numOfTests = int(self.fIn.readline())
        self.input = []
        for t in range(self.numOfTests):
            self.fIn.readline()
            N = int(self.fIn.readline())
            enemies = []
            for j in range(N):
                enemies.append(map(int, self.fIn.readline().split())[1:])
            self.input.append((N, enemies))

    def __init__(self):
        self.fIn = open('input.txt')
        self.fOut = open('output.txt', 'w')
        self.results = []

    def parallel(self):
        self.getInput()
        p = Pool(4)
        millis1 = int(round(time.time() * 1000))
        self.results = p.map(solve, self.input)
        millis2 = int(round(time.time() * 1000))
        print("Time in milliseconds: %d " % (millis2 - millis1))
        self.makeOutput()

    def sequential(self):
        self.getInput()
        millis1 = int(round(time.time() * 1000))
        for i in self.input:
            self.results.append(solve(i))
        millis2 = int(round(time.time() * 1000))
        print("Time in milliseconds: %d " % (millis2 - millis1))
        self.makeOutput()

    def makeOutput(self):
        for test in range(self.numOfTests):
            self.fOut.write("%s\n" % self.results[test])
        self.fIn.close()
        self.fOut.close()

if __name__ == '__main__':
    solver = Solver()
    if parallelSolve:
        solver.parallel()
    else:
        solver.sequential()
