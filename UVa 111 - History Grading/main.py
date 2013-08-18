'''
Created on Jul 20, 2013
@author: Yubin Bai
'''
import sys
INF = 1 << 31


def LIS(array):
    N = len(array)
    longest = [0] * N
    longest[0] = 1
    for i in range(1, N):
        currMax = 1
        for j in range(i):
            if array[i] >= array[j] and longest[j] + 1 > currMax:
                currMax = longest[j] + 1
        longest[i] = currMax
    return max(longest)


def solve(par):
    N, answer, students = par
    rankOf = [0] * N
    for i, a in enumerate(answer):
        rankOf[i] = a - 1  # rank of item i
    stu = []
    for s in students:
        currS = [0] * N
        for i, a in enumerate(s):
            currS[a - 1] = rankOf[i]
                # ans (a - 1) contains element of rankOf[i]
        stu.append(currS)
    result = [LIS(s) for s in stu]
    return '\n'.join(str(r) for r in result)


if __name__ == '__main__':
    sys.stdin = open('input.txt', 'r')
    N = int(input())
    answer = map(int, raw_input().split())
    students = []
    while True:
        try:
            students.append(map(int, raw_input().split()))
        except:
            break
    print(solve((N, answer, students)))
