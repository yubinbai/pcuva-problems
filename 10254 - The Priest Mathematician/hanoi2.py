'''
6.6.6 The Priest Mathematician
PC/UVa IDs: 110606/10254, Popularity: C, Success rate: high Level: 2
'''
import sys
MAXN = 10009

if __name__ == '__main__':
    f = open('input.txt')
    memo4 = {0: 0, 1: 1}
    diff = 2
    p = 2
    while p in range(1, MAXN):
        diffPow = 1 << (diff - 1)
        for i in range(diff):
            memo4[p] = memo4[p - 1] + diffPow
            p += 1
        diff += 1
        

    for line in f:
        if line == '':
            break
        disks = int(line)
        print(memo4[disks])
