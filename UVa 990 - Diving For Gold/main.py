import sys
INF = 1 << 31


def solve(par):
    T, W, N, items = par
    value = [e[1] for e in items]
    cost = [3 * W * e[0] for e in items]
    totalCost = sum(cost)

    memo = [0] * (totalCost + 1)
    prev = [-1] * (totalCost + 1)
    for i in range(N):
        for j in range(totalCost, -1, -1):
            if j >= cost[i]:
                # print(j, j - cost[i])
                v = memo[j - cost[i]] + value[i]
                if v > memo[j]:
                    memo[j] = v
                    prev[j] = i
    remain = T
    path = []
    while remain >= 0 and prev[remain] != -1:
        p = prev[remain]
        path.append(items[p])
        remain -= cost[p]
    for i, p in enumerate(path):
        path[i] = ' '.join(str(e) for e in p)
    return '%d\n%d\n%s' % (memo[T], len(path), '\n'.join(path))

if __name__ == '__main__':
    sys.stdin = open('input.txt', 'r')
    while True:
        try:
            T, W = map(int, raw_input().split())
        except:
            break
        N = int(input())
        array = []
        for i in range(N):
            array.append(map(int, raw_input().split()))
        print(solve((T, W, N, array)))
