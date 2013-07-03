'''
1.6.1
The 3n + 1 Problem
PC/UVa IDs: 110101/100, Popularity: A, Success rate: low Level: 1
'''


def clojureL(n, memo):
    if n in memo:
        return memo[n]
    if n % 2 == 0:
        l = clojureL(n / 2, memo)
    else:
        l = clojureL(3 * n + 1, memo)
    memo[n] = l + 1
    return memo[n]

if __name__ == '__main__':
    memo = {1: 1}

    f = open('input.txt')

    numOfTests = int(f.readline())
    for i in range(numOfTests):
        x, y = [int(a) for a in f.readline().split()]
        currMax = 0
        for n in range(x, y + 1):
            if currMax < clojureL(n, memo):
                currMax = clojureL(n, memo)

        print(currMax)
