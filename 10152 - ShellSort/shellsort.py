'''
4.6.7 ShellSort
PC/UVa IDs: 110407/10152, Popularity: B, Success rate: average Level: 2
'''


def findPos(seqNum, num):
    for i in range(len(seqNum)):
        if seqNum[i] == num:
            return i
    return None


def moveTop(array, j):
    temp = array[j]
    for i in range(j, 0, -1):
        array[i] = array[i - 1]
    array[0] = temp


def sortSequence(startOrder, endOrder, result):
    n = len(startOrder)
    endDict = {}
    for i in range(len(endOrder)):
        endDict[endOrder[i]] = i

    # get start sequence in numbers
    seqNum = []
    for i in startOrder:
        seqNum.append(endDict[i])

    for curr in range(n - 1, 0, -1):
        posCurr = findPos(seqNum, curr)
        posNext = findPos(seqNum, curr - 1)
        if posCurr < posNext:
            moveTop(seqNum, posNext)
            result.append(endOrder[curr - 1])

if __name__ == '__main__':
    f = open('input.txt')
    numOfTests = int(f.readline())

    for t in range(numOfTests):
        lines = int(f.readline())
        startOrder = []
        for i in range(lines):
            startOrder.append(f.readline().rstrip())

        endOrder = []
        for i in range(lines):
            endOrder.append(f.readline().rstrip())

        result = []
        sortSequence(startOrder, endOrder, result)
        print('\n'.join(result))
        print('')
