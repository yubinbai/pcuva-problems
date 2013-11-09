import sys
import numpypy as np

sys.stdin = open('input.txt')
case = 0
while True:
    n = int(input())
    case += 1
    if not n:
        break
    block = []
    for _ in range(n):
        block.append(sorted(map(int, raw_input().split())))
    memo = np.zeros((2, n, 3), np.int)
    for i in range(n):
        for k in range(3):
            memo[0, i, k] = block[i][k]
    for step in range(1, n * 3):
        for i1 in range(n):
            for k1 in range(3):
                for i2 in range(n):
                    for k2 in range(3):
                        addH = block[i2][k2]
                        v1 = list(block[i1])
                        del v1[k1]
                        v2 = list(block[i2])
                        del v2[k2]
                        if v1[0] < v2[0] and v1[1] < v2[1]:
                            memo[step % 2, i2, k2] = max(
                                addH + memo[(step - 1) % 2, i1, k1],
                                memo[step % 2, i2, k2])
    print 'Case %d: maximum height =' % case, memo.max()
