import sys
import numpypy as np

sys.stdin = open('input.txt')
itertest = 0
while True:
    try:
        N = int(input())
    except:
        break
    graph = np.empty((N, N))
    for i in range(N):
        line = map(float, raw_input().split())
        line.insert(i, 1.0)
        for j in range(N):
            graph[i, j] = line[j]

    def DLS(curr, path, depth):
        if depth == 0:
            if graph[path[-1], path[0]] * curr >= 1.01:
                path.append(path[0])
                return graph[path[-1], path[0]] * curr
            else:
                return 0
        for i in range(N):
            if i not in path:
                curr2 = curr * graph[path[-1], i]
                path.append(i)
                value = DLS(curr2, path, depth - 1)
                if value > 0:
                    return value
                path.pop()
        return 0
    itertest += 1
    print 'Case: %d' % itertest
    flag = False
    maxProfit, resultPath = 0, None
    for depth in range(1, N + 1):
        for start in range(N):
            path = [start]
            value = DLS(1.0, path, depth)
            if value > maxProfit:
                maxProfit = value
                resultPath = [p + 1 for p in path]
                flag = True
        if flag:
            print 'depth = %d' % depth
            break
    if flag:
        print resultPath, maxProfit
    else:
        print 'no solution'
