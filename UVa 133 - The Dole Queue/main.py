import sys

sys.stdin = open('input.txt')
while True:
    N, k, m = map(int, raw_input().split())
    if not N:
        break
    circle = list(range(1, N + 1))
    visited = [False] * (N)

    curr1 = N - 1
    curr2 = 0
    remainCount = N

    while remainCount > 0:
        counter = 0
        while counter < k:
            curr1 = (curr1 + 1) % N
            if not visited[curr1]:
                counter += 1
        counter = 0
        while counter < m:
            curr2 = (curr2 - 1 + N) % N
            if not visited[curr2]:
                counter += 1

        if curr1 == curr2:
            print '%3d' % circle[curr1]
            visited[curr1] = True
            remainCount -= 1
        else:
            print '%3d %3d' % (circle[curr1], circle[curr2])
            visited[curr1] = True
            visited[curr2] = True
            remainCount -= 2
