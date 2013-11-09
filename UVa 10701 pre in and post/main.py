import sys


class TreeNode(object):

    def __init__(self, data):
        super(TreeNode, self).__init__()
        self.data = data
        self.left = self.right = None


def makeTree(preOrder, inOrder):
    if len(preOrder) == 0:
        return None
    if len(preOrder) == 1:
        return TreeNode(preOrder[0])
    k = inOrder.index(preOrder[0])
    t = TreeNode(preOrder[0])
    t.left = makeTree(preOrder[1:k + 1], inOrder[:k])
    t.right = makeTree(preOrder[k + 1:], inOrder[k + 1:])
    return t


def postTrans(tree):
    if tree:
        return postTrans(tree.left) + postTrans(tree.right) + tree.data
    else:
        return ''
sys.stdin = open('input.txt')
for _ in range(int(input())):
    n, s1, s2 = raw_input().strip().split()
    t = makeTree(s1, s2)
    print postTrans(t)
