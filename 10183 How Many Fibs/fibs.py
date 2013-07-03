'''
6.6.1 How Many Fibs?
PC/UVa IDs: 110601/10183, Popularity: B, Success rate: average Level: 1
'''
import itertools


def getFibs(size):
    yield 1
    currFib = 1
    nextFib = 1
    while nextFib < size:
        currFib, nextFib = nextFib, currFib + nextFib
        yield nextFib

if __name__ == '__main__':
    fibs = list(getFibs(10 ** 100))
    f = open('input.txt')
    while True:
        start, end = [int(x) for x in f.readline().split()]
        if start == 0:
            break
        print(len([e for e in fibs if e <= end and e >= start]))
