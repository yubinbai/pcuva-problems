'''
6.6.6 The Priest Mathematician
PC/UVa IDs: 110606/10254, Popularity: C, Success rate: high Level: 2
'''
import sys
MAXN = 20000


def hanoi3(disks):
    if memo3[disks] != -1:
        return memo3[disks]
    if disks == 0:
        memo3[disks] = 0
        return 0
    memo3[disks] = 2 * hanoi3(disks - 1) + 1
    return memo3[disks]


def hanoi4(disks):
    if memo4[disks] != -1:
        return memo4[disks]
    currMin = hanoi3(disks)
    for k in range(1, disks):
        s = 2 * hanoi4(k) + hanoi3(disks - k)
        if s < currMin:
            currMin = s
    memo4[disks] = currMin
    return currMin

if __name__ == '__main__':
    f = open('input.txt')
    sys.setrecursionlimit(MAXN)
    memo3 = [-1 for x in range(MAXN)]
    memo4 = [-1 for x in range(MAXN)]
    for line in f:
        if line == '':
            break
        disks = int(line)
        print(hanoi4(disks))

    diff = [memo4[i] - memo4[i - 1] for i in range(2, 100)]
