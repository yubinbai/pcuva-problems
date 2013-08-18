'''
Created on Jun 20, 2013
@author: Yubin Bai
'''
import sys
INF = 1 << 32


def solve(n, t, distance, toll):
    memo = []
    for i in range(n):
        memo.append([(None, None)] * (t + 1))

    def go(currCity, time_left):
        if time_left < 0:
            return INF, INF
        if currCity == n - 1:
            return 0, 0
        if memo[currCity][time_left][0] != None:
            return memo[currCity][time_left]
        minCost = INF, INF
        for neighbor in range(n):
            if currCity != neighbor:
                nextCity = go(
                    neighbor, time_left - distance[currCity][neighbor])
                # pick neighbor at min cost
                if nextCity[0] + toll[currCity][neighbor] < minCost[0]:
                    minCost = nextCity[0] + toll[currCity][neighbor], \
                        nextCity[1] + distance[currCity][neighbor]
        memo[currCity][time_left] = minCost
        return minCost
    return '%d %d' % go(0, t)

if __name__ == '__main__':
    sys.stdin = open('input.txt')
    while True:
        n, t = map(int, raw_input().split())
        if n == 0:
            break
        distance = []
        for i in range(n):
            distance.append(map(int, raw_input().split()))
        raw_input()
        toll = []
        for i in range(n):
            toll.append(map(int, raw_input().split()))
        raw_input()
        print(solve(n, t, distance, toll))
