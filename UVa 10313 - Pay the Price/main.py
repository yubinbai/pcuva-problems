import sys
INF = 1 << 31
MAXN = 305


if __name__ == '__main__':

    memo = []
    for i in range(MAXN):  # use 1..i coins
        memo.append([0] * (MAXN))  # ways to make
    memo[0][0] = 1
    for coin in range(301):
        for i in range(1, MAXN):
            for j in range(coin, MAXN):
                memo[i][j] += memo[i - 1][j - coin]

    sys.stdin = open('input.txt', 'r')
    while True:
        try:
            row = map(int, raw_input().split())
        except:
            break
        N = row[0]
        if len(row) == 1:
            print(memo[N][N])
        elif len(row) == 2:
            print(memo[row[1]][N])
        elif len(row) == 3:
            if row[1] == 0:
                print(memo[row[2]][N])
            else:
                print(memo[row[2]][N] - memo[row[1] - 1][N])
