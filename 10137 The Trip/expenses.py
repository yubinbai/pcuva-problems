'''
1.6.3
17
The Trip
PC/UVa IDs: 110103/10137

'''


def transferAmount(expensesInCents, n):
    currSumInCents = 0
    for i in expensesInCents:
        currSumInCents += i

    averageInCents = currSumInCents // n

    leftoverCents = currSumInCents % n

    # if a person is paying more than average, let him lose the extra cent
    # to minimize transfer

    transferInCents = 0

    for i in expensesInCents:
        if i >= averageInCents:
            if leftoverCents > 0:
                transferInCents += i - averageInCents - 1
                leftoverCents -= 1
            else:
                transferInCents += i - averageInCents

    return transferInCents


if __name__ == '__main__':

    f = open('input.txt')
    numOfTests = int(f.readline())
    for i in range(numOfTests):
        n = int(f.readline().strip())
        expensesInCents = []
        for j in range(n):
            expensesInCents.append(int(float(f.readline()) * 100))

        print("$%.2f" % (transferAmount(expensesInCents, n) / 100.0))
