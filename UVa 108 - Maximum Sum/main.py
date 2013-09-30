import sys


def solve(par):
    N, mat = par

    maxSubRect = -127 * 100 * 100  # lowest possible value for this problem

    arr = []
    for i in range(N):
        arr.append([0] * N)

    arr[0][0] = mat[0][0]
    for i in range(1, N):
        arr[0][i] = arr[0][i - 1] + mat[0][i]

    for i in range(1, N):
        row = [0] * N
        row[0] = mat[i][0]
        for j in range(1, N):
            row[j] = row[j - 1] + mat[i][j]
        for j in range(N):
            arr[i][j] = row[j] + arr[i - 1][j]

    for i in range(N):
        for j in range(N):
            for k in range(i, N):
                for l in range(j, N):
                    subRect = arr[k][l]
                    if (i > 0):
                        subRect -= arr[i - 1][l]  # O(1)
                    if (j > 0):
                        subRect -= arr[k][j - 1]  # O(1)
                    if (i > 0 and j > 0):
                        subRect += arr[i - 1][
                            j - 1]  # inclusion-exclusion: O(1)
                    maxSubRect = max(maxSubRect, subRect)

    return maxSubRect

if __name__ == '__main__':
    sys.stdin = open('input.txt', 'r')
    N = int(input())
    buff = []
    while True:
        try:
            buff += map(int, raw_input().split())
        except:
            break
    i = j = 0
    mat = [[None] * N for _ in range(N)]
    for x in buff:
        mat[i][j] = x
        j += 1
        if j == N:
            j = 0
            i += 1
    print(solve((N, mat)))
