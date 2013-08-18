import sys
INF = 1 << 31


def solve(par):
    M, S, coins = par
    memo = []
    for i in range(S + 1):
        memo.append([INF] * (S + 1))
    memo[0][0] = 0
    for coin in coins:
        for i in range(coin[0], S + 1):
            for j in range(coin[1], S + 1):
                memo[i][j] = min(
                    memo[i][j], memo[i - coin[0]][j - coin[1]] + 1)

    minNum = INF
    for i in range(S + 1):
        for j in range(S + 1):
            if i ** 2 + j ** 2 == S ** 2:
                minNum = min(minNum, memo[i][j])
    if minNum == INF:
        return 0
    else:
        return minNum


if __name__ == '__main__':
    sys.stdin = open('input.txt', 'r')
    numTest = int(input())
    for test in range(numTest):
        M, S = map(int, raw_input().split())
        coins = []
        for i in range(M):
            coins.append(map(int, raw_input().split()))
        res = solve((M, S, coins))
        if res:
            print(res)
        else:
            print('not possible')
