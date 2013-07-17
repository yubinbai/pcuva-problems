'''
Created on 2013-6-19

@author: Yubin Bai

1079 - A Careful Approach
'''
import itertools


def solve(n, a, b):

    def greedyLanding():
        # try landing those planes and see what is the gap to b[order[n - 1]]
        lastLanding = a[order[0]]  # greedy, first aircraft lands immediately
        for i in range(1, n):
            # for the other aircrafts
            targetLandingTime = lastLanding + timeGap
            if targetLandingTime <= b[order[i]]:
                # this aircraft can land, greedily choose max of a[order[i]] or
                # targetLandingTime
                lastLanding = max(a[order[i]], targetLandingTime)
            else:
                return 1  # returning positive value will force binary search to reduce timeGap

        # returning negative value will force binary search to increase timeGap
        return lastLanding - b[order[n - 1]];

    order = [0] * n
    for i in range(n):
        a[i] *= 60
        b[i] *= 60
        order[i] = i
    maxTimeGap = -1  # variable to be searched for
    p = itertools.permutations(order, n)
    for order in p:
        lowVal = 0
        highVal = 86400
        timeGap = -1
        while (abs(lowVal - highVal) > 1E-3):
            timeGap = (lowVal + highVal) / 2.0
            retVal = greedyLanding()
            if retVal <= 1E-2:
                lowVal = timeGap
            else:
                highVal = timeGap
        maxTimeGap = max(maxTimeGap, timeGap)
    maxTimeGap = int(maxTimeGap + 0.5)
    return '%d:%02d' % (maxTimeGap // 60, maxTimeGap % 60)

if __name__ == "__main__":
    n = 3
    a = [0, 5, 10]
    b = [10, 15, 15]
    print(solve(n, a, b))
    n = 2
    a = [0, 10]
    b = [10, 20]
    print(solve(n, a, b))
