import sys


def backtrack(total, step):
    if total > maxTotal:
        return
    if step == N:
        if total >= best[1]:
            best[0] = list(path)
            best[1] = sum(path)
        return

    backtrack(total, step + 1)
    path.append(A[step])
    backtrack(total + A[step], step + 1)
    path.pop()

sys.stdin = open('input.txt')
while True:
    path = []
    best = [None, None]
    try:
        A = map(int, raw_input().split())
    except:
        break
    maxTotal, N = A[0], A[1]
    del A[0:2]
    backtrack(0, 0)
    print best[0], 'sum: %d' % sum(best[0])
