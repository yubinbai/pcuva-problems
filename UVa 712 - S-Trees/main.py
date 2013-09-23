import sys
from bitstring import BitArray

sys.stdin = open('input.txt')
while True:
    N = int(input())
    if not N:
        break
    pos = map(int, raw_input().strip().replace('x', '').split())
    # print pos
    tree = BitArray('0b' + raw_input().strip())
    M = int(input())
    result = []
    for i in range(M):
        q = raw_input().strip()
        node = 0
        for i, p in enumerate(pos):
            if q[p - 1] == '0':
                node *= 2
            else:
                node *= 2
                node += 1
        if tree[node]:
            result.append('1')
        else:
            result.append('0')
    print ''.join(result)
