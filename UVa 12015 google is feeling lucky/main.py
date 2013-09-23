import sys

sys.stdin = open('input.txt')
numTest = int(input())
for itertest in range(numTest):
    highV, highList = 0, []
    for x in xrange(1, 11):
        name, v = raw_input().split()
        v = int(v)
        if v > highV:
            highV = v
            highList = [name]
        elif v == highV:
            highList.append(name)
    print 'Case #%d:' % (itertest + 1)
    print '\n'.join(highList)
