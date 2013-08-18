import sys
INF = 1 << 31


def solve(par):
    N, array = par
    total = sum(array)
    memo = [0] * (total + 1)
    memo[0] = 1
    memo[array[0]] = 1
    for i in range(1, N):
        for j in range(total + 1, -1, -1):
            if (j >= array[i] and memo[j - array[i]] == 1):
                memo[j] = 1
    minDiff = INF
    for i in range(total + 1):
        if memo[i]:
            minDiff = min(minDiff, abs(total - 2 * i))

    return minDiff

if __name__ == '__main__':
    sys.stdin = open('input.txt', 'r')
    numTests = int(input())
    for itertest in range(numTests):
        N = int(input())

        array = map(int, raw_input().split())
        print(solve((N, array)))
