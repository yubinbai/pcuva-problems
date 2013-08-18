def getNew(number):
    nList = list(str(number))
    nList.sort()
    back = ''.join(nList)
    nList.reverse()
    forward = ''.join(nList)
    newN = int(forward) - int(back)
    return forward, back, newN

inFile = open('input.txt')
for line in inFile:
    if line.strip() == '0':
        break
    numSet = set()
    N = int(line)
    numSet.add(N)
    while True:
        forward, back, N = getNew(N)
        print '%s - %s = %d' % (forward, back, N)
        if N in numSet:
            print 'Chain length %d\n' % len(numSet)
            break
        else:
            numSet.add(N)
