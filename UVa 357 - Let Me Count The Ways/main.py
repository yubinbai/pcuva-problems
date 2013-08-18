import sys

coins = [1, 5, 10, 25, 50]
MAXN = 30000
memo = [0] * MAXN


if __name__ == '__main__':
    sys.stdin = open('input.txt', 'r')
    memo[0] = 1
    for i in range(5):
        for j in range(coins[i], MAXN):
            memo[j] += memo[j - coins[i]]

    while True:
        try:
            N = int(input())
        except:
            break
        if memo[N] == 1:
            print('There is only 1 way to produce %d cents change.' % (N))
        else:
            print('There are %d ways to produce %d cents change.' %
                  (memo[N], N))
