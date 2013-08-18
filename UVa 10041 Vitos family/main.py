import sys


def solve(par):
    N, array = par
    array.sort()
    d = 0
    if N % 2:
        mid = array[N // 2]
    else:
        mid = 0.5 * (array[N // 2 - 1] + array[N // 2])
    for a in array:
        d += abs(a - mid)
    return int(d)

if __name__ == '__main__':
    sys.stdin = open('input.txt')
    numTest = int(input())
    for itertest in range(numTest):
        row = map(int, raw_input().split())
        print(solve((row[0], row[1:])))
