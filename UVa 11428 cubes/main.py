import sys
import itertools

cubes = [x ** 3 for x in range(59)]


def find(n):
    for a in range(1, 58):
        for b in range(a + 1, 59):
            if cubes[b] - cubes[a] == n:
                return a, b
    return None, None


sys.stdin = open('input.txt')
while True:
    n = int(input())
    if not n:
        break
    a, b = find(n)
    if not a:
        print 'No solution'
    else:
        print b, a
