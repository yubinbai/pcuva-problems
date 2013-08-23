from itertools import chain
from numpypy import *
import sys

sys.stdin = open('input.txt')
numTest = int(input())
for itertest in range(numTest):
    raw_input()
    flightsA = []
    for i in range(int(input())):
        flightsA.append(raw_input().strip().split())
    flightsB = []
    for i in range(int(input())):
        flightsB.append(raw_input().strip().split())
    nodes = set()
    for t in chain(flightsA):
        nodes.add(t[0])
        nodes.add(t[1])
    nodesB = set()
    for t in chain(flightsB):
        nodesB.add(t[0])
        nodesB.add(t[1])
    if nodes != nodesB:
        print 'NO'
    else:
        nodes = list(nodes)
        N = len(nodes)
        nodes = dict([(nodes[i], i) for i in range(N)])
        graphA = zeros((N, N), dtype=byte)
        for f, t in flightsA:
            graphA[nodes[f], nodes[t]] = 1
            graphA[nodes[t], nodes[f]] = 1
        graphB = zeros((N, N), dtype=byte)
        for f, t in flightsB:
            graphB[nodes[f], nodes[t]] = 1
            graphB[nodes[t], nodes[f]] = 1
        # print graphA
        # print graphB

        for k in range(N):
            for i in range(N):
                for j in range(N):
                    graphA[i, j] = graphA[i, j] | (graphA[i, k] & graphA[k, j])
                    graphB[i, j] = graphB[i, j] | (graphB[i, k] & graphB[k, j])
        if all(graphA == graphB):
            print 'YES'
        else:
            print 'NO'
        # print graphA
        # print graphB
