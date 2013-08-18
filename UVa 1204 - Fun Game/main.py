'''
Created on Jul 26, 2013
@author: Yubin Bai

this problem is too hard for me.
it looks like tsp, but actually not at all...
brute force 16! seems unreal.
'''
import sys
INF = 1 << 31


def solve(par):
    N, mat = par


if __name__ == '__main__':
    sys.stdin = open('input.txt', 'r')
    while True:
        N = int(input())
        mat = []
        for i in range(N):
            mat.append(raw_input().strip())

        print(solve((N, mat)))
