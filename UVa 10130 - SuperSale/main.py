import sys
INF = 1 << 31


def solve(par):
    G, capacity, N, items = par
    value = [e[0] for e in items]
    cost = [e[1] for e in items]
    totalCost = sum(cost)

    memo = [0] * (totalCost + 1)
    for i in range(N):
        for j in range(totalCost, -1, -1):
            if j >= cost[i]:
                # print(j, j - cost[i])
                v = memo[j - cost[i]] + value[i]
                if v > memo[j]:
                    memo[j] = v

    return sum(memo[c] for c in capacity)


if __name__ == '__main__':
    sys.stdin = open('input.txt', 'r')
    numTests = int(input())
    for itertest in range(numTests):
        N = int(input())
        array = []
        for i in range(N):
            array.append(map(int, raw_input().split()))
        G = int(input())
        capacity = []
        for i in range(G):
            capacity.append(int(input()))
        print(solve((G, capacity, N, array)))
