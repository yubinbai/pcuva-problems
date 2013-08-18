'''
Created on Jul 24, 2013
@author: Yubin Bai
'''
import sys
INF = 1 << 31


def solve(par):
    N, array, b, r, v, e, f = par
    dp = [INF] * (N + 1)
    dp[0] = 0
    for i in range(N):
        for j in range(i + 1, N + 1):
            if i == 0:
                dist = array[j - 1]
            else:
                dist = array[j - 1] - array[i - 1]
            # print i, j, dist
            time = 0.0
            for x in range(dist):
                if x >= r:
                    time += 1.0 / (v - e * (x - r))
                else:
                    time += 1.0 / (v - f * (r - x))
            if i == 0:
                dp[j] = min(dp[j], dp[i] + time)
            else:
                dp[j] = min(dp[j], dp[i] + time + b)
    return '%.5f' % dp[N]

if __name__ == '__main__':
    sys.stdin = open('input.txt', 'r')
    while True:
        N = int(input())
        if N == 0:
            break
        array = map(int, raw_input().split())
        b = float(raw_input())
        r, v, e, f = map(float, raw_input().split())
        print(solve((N, array, b, r, v, e, f)))
