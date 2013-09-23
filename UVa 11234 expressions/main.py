import sys
from collections import deque
from collections import namedtuple

TreeNode = namedtuple('TreeNode', ['data', 'left', 'right'])

def getTree(exp):
    stack = []
    for e in exp:
        if ord(e) >= ord('A') and ord(e) <= ord('Z'):
            t1 = stack.pop()
            t2 = stack.pop()
            t3 = TreeNode(e, t1, t2)
            stack.append(t3)
        else:
            stack.append(e)
    return stack[-1]

def layer(tree):
    result = []
    q = deque()
    q.append(tree)
    while q:
        e = q.popleft()
        try:
            result.append(e.data)
            q.append(e.right)
            q.append(e.left)
        except:
            result.append(e)
    return result

sys.stdin = open('input.txt')
numTest = int(input())
for itertest in range(numTest):
    exp = raw_input().strip()
    tree = getTree(exp)
    result = layer(tree)
    print ''.join(reversed(result))
