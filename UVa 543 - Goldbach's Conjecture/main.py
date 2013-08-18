from bitstring import *


def sieve(top=500005):
    s = BitArray(top)
    for x in range(2, top):
        if not s[x]:
            yield x
            s.set(True, range(x * x, top, x))


def twoSum(number, nList):
    left = 0
    right = len(nList) - 1
    while left < right:
        if nList[left] + nList[right] < number:
            left += 1
        elif nList[left] + nList[right] > number:
            right -= 1
        else:
            return '%d = %d + %d' % (number, nList[left], nList[right])


if __name__ == '__main__':
    primes = list(sieve())
    inFile = open('input.txt')
    for line in inFile:
        n = int(line)
        if n == 0:
            break
        print(twoSum(n, primes))
