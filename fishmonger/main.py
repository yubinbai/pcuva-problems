'''
Created on Jun 20, 2013

@author: Yubin Bai

All rights reserved.
'''
import sys
infinity = 1 << 32


def solve(n, t, distance, toll):
    memo = []
    for i in range(n):
        memo.append([(None, None)] * (t + 1))

    def go(curCity, time_left):
        if time_left < 0:
            return infinity, infinity
        if curCity == n - 1:
            return 0, 0
        if memo[curCity][time_left][0] != None:
            return memo[curCity][time_left]
        answer = infinity, infinity
        for neighbor in range(n):
            if curCity != neighbor:
                nextCity = go(
                    neighbor, time_left - distance[curCity][neighbor])
                # pick neighbor at min cost
                if nextCity[0] + toll[curCity][neighbor] < answer[0]:
                    answer = nextCity[0] + toll[curCity][neighbor], \
                        nextCity[1] + distance[curCity][neighbor]
        memo[curCity][time_left] = answer
        return answer
    result = go(0, t)
    return '%d %d' % (result[0], result[1])

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
