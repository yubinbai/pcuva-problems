import sys
from collections import defaultdict

sys.stdin = open('input.txt')
numTest = int(input())
raw_input()
for itertest in range(numTest):
    weight = {}
    connected = defaultdict(list)
    cost = {}
    while True:
        try:
            line = raw_input().strip()
        except:
            break
        if len(line) == 0:
            break
        row = line.split()
        weight[row[0]] = int(row[1])
        if len(row) != 2:
            connected[row[0]] = list(row[2])

    def getCost(node):
        if node in cost:
            return cost[node]
        if not connected[node]:
            return weight[node]
        else:
            m = max(getCost(w) for w in connected[node])
            return m + weight[node]
    print max(getCost(w) for w in weight)
    print
