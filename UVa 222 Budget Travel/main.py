'''
Created on Jul 14, 2013
@author: Yubin Bai
'''
import time
from multiprocessing.pool import Pool
parallelSolve = False
INF = 1 << 31


def solve(par):

    def dfs(currDist, currGas, currCost):
        '''
        dfs to get the results
        currDist - dist from origin
        currCost - cash spent so far
        return true if destination is reached
        '''
        if currCost > minCost[0] or currGas < 0.0:
            return False

        if distOfDestination - currDist <= currGas * mpg:
            minCost[0] = min(minCost[0], currCost)
            return True

        reached = False
        for s in stations:
            if s[0] <= currDist or s[0] - currDist > currGas * mpg:
                continue
            lastDriveGas = (s[0] - currDist) / mpg
            r1 = dfs(s[0], currGas - lastDriveGas, currCost)
            if not r1 or currGas - lastDriveGas <= capacity / 2.0:
                r2 = dfs(s[0], capacity, currCost + round((
                    capacity - (currGas - lastDriveGas)) * s[1]) + 200)
            if r1 or r2:
                reached = True
        return reached

    distOfDestination, capacity, mpg, gasPriceOrigin, N, stations = par
    stations.sort()
    minCost = [INF]
    dfs(0.0, capacity, int(gasPriceOrigin))
    return '%.2f' % (minCost[0] / 100.0)


class Solver:

    def getInput(self):
        self.numOfTests = 0
        self.input = []
        while True:
            dist = float(self.fIn.readline())
            if dist < 0:
                break
            self.numOfTests += 1
            capacity, mpg, gasPriceOrigin, N = map(
                float, self.fIn.readline().split())
            gasPriceOrigin *= 100
            N = int(N)
            stations = []
            for i in range(N):
                stations.append(map(float, self.fIn.readline().split()))

            self.input.append(
                (dist, capacity, mpg, gasPriceOrigin, N, stations))

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
