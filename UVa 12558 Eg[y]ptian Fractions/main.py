import sys
DEPTH_LIMIT = 4
INF = 1100
EPS = 1e-9


sys.stdin = open('input.txt')
numTest = int(input())
for itertest in range(numTest):
    row = map(int, raw_input().split())
    a, b = row[0], row[1]
    forbidden = row[3:]

    def DLS(v, depth):
        if depth == 0:
            if abs(v) < EPS:
                result.extend(path)
            return
        if len(result) > 0:
            return

        if path:
            start = path[-1] + 1
        else:
            start = 2
        for x in range(start, INF):
            if x not in forbidden:
                remain = v - 1.0 / x
                path.append(x)
                DLS(remain, depth - 1)
                path.pop()

    path = []
    result = []
    for depth in range(1, DEPTH_LIMIT):
        DLS(a * 1.0 / b, depth)
        if result:
            break
    print '%d / %d = ' % (a, b)
    for p in result:
        print '1/%d + ' % p,
    print
