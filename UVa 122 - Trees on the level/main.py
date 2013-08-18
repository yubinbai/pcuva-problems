import sys
from collections import deque


class TreeNode(object):

    """tree node for binary tree"""

    def __init__(self, data=None):
        self.data = data
        self.left = self.right = None

sys.stdin = open('input.txt')
for line in sys.stdin:
    nodes = line.strip().split()
    root = TreeNode()
    for e in nodes:
        print e
        e = e.strip('()')
        if e == '':
            continue
        data, pos = e.split(',')
        currNode = root
        for p in pos:
            if p == 'L':
                if currNode.left:
                    currNode = currNode.left
                else:
                    currNode.left = TreeNode()
                    currNode = currNode.left
            else:
                if currNode.right:
                    currNode = currNode.right
                else:
                    currNode.right = TreeNode()
                    currNode = currNode.right
        currNode.data = data

    result = []
    currLevel = deque([root])
    nextLevel = deque()
    while currLevel:
        e = currLevel.popleft()
        if e.data:
            result.append(e.data)
            if e.left:
                nextLevel.append(e.left)
            if e.right:
                nextLevel.append(e.right)
        if not currLevel:
            currLevel, nextLevel = nextLevel, currLevel
    print ' '.join(result)
