from pyparsing import OneOrMore, nestedExpr
from collections import Counter


def treeSum(value, tree):
    if not tree:
        return value == 0
    v1 = value - int(tree[0])
    for t in tree[1:]:
        if treeSum(v1, t):
            return True
    return False

inFile = open('input.txt')
openBrac = 0
currExp = ''
for line in inFile:
    line.strip()
    lineCounter = Counter(list(line))
    if '(' not in lineCounter:
        lineCounter['('] = 0
    if ')' not in lineCounter:
        lineCounter[')'] = 0
    openBrac += lineCounter['('] - lineCounter[')']
    currExp += line
    if openBrac != 0:
        continue
    else:
        row = currExp.split()
        currExp = ''
        openBrac = 0
        value = int(row[0])
        exp = ''.join(row[1:])
        exp = OneOrMore(nestedExpr()).parseString(exp)
        # print value, exp
        if treeSum(value, exp[0]):
            print 'yes'
        else:
            print 'no'
