import sys
import math
import itertools


def find(i):
    if parent[i] != i:
        parent[i] = find(parent[i])
    return parent[i]


def union(i, j):
    p1 = i
    while parent[p1] != p1:
        p1 = parent[p1]
    p2 = j
    while parent[p2] != p2:
        p2 = parent[p2]
    if rank[p1] < rank[p2]:
        parent[p1] = p2
    else:
        parent[p2] = p1
        if rank[p1] == rank[p2]:
            rank[p1] += 1


def extended_gcd(a, b):
    '''
    return gcd, x0, y0
    for equation ax+by=g
    '''
    x, y = 0, 1
    lastx, lasty = 1, 0
    while b:
        q = a // b
        a, b = b, a % b
        x, lastx = lastx - q * x, x
        y, lasty = lasty - q * y, y
    return a, lastx, lasty

sys.stdin = open('input.txt')
numTest = int(input())
for itertest in range(numTest):
    F, E, A, B = map(int, raw_input().split())
    rank = [0] * E
    parent = list(range(E))
    elevators = []
    for i in range(E):
        elevators.append(map(int, raw_input().split()))

    for e1, e2 in itertools.combinations(range(E), 2):
        x1, y1 = elevators[e1]
        x2, y2 = elevators[e2]
        gcd, a, b = extended_gcd(x1, x2)
        m = y2 - y1
        if m % gcd:
            continue
        else:
            m /= gcd
            a *= m
            b *= m
            s = -1.0 * (x1 * a + y1) * gcd / (x1 * x2)
            t, s = int(math.ceil(s)), int(math.floor(s))
            p = a + s * x2 / gcd  # additional solutions
            q = b - s * x1 / gcd
            if 0 <= x1 * p + y1 and x1 * p + y1 < F:
                union(e1, e2)
            p = a + t * x2 / gcd
            q = b - t * x1 / gcd
            if 0 <= x1 * p + y1 and x1 * p + y1 < F:
                union(e1, e2)

    elevA, elevB = [], []
    for e in range(E):
        x, y = elevators[e]
        if A % x == y % x and A >= y:
            elevA.append(e)
        if B % x == y % x and B >= y:
            elevB.append(e)
    flag = False
    for a in elevA:
        for b in elevB:
            if find(a) == find(b):
                flag = True
                break
        if flag:
            break
    if flag:
        print 'It is possible to move the furniture.'
    else:
        print 'The furniture cannot be moved.'
