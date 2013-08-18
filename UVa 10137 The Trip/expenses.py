'''
The Trip
PC/UVa IDs: 110103/10137
'''


def transferAmount(expenses, n):
    currSum = sum(expenses)
    average = currSum // n
    leftoverCents = currSum % n
    # if a person is paying more than average, let him lose the extra cent
    # to minimize transfer
    transfer = 0
    for i in expenses:
        if i >= average:
            if leftoverCents > 0:
                transfer += i - average - 1
                leftoverCents -= 1
            else:
                transfer += i - average
    return transfer


if __name__ == '__main__':

    f = open('input.txt')
    while True:
        n = int(f.readline().strip())
        if not n:
            break
        expenses = []
        for j in range(n):
            # convert everything to cents
            expenses.append(int(float(f.readline()) * 100))
        print("$%.2f" % (transferAmount(expenses, n) / 100.0))
