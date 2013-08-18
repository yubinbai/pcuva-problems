def solve(n, a):
    total = 0
    currA = a
    for i in range(1, n + 1):
        total += i * currA
        currA *= a
    return total

if __name__ == '__main__':
    print solve(3, 3)
    print solve(4, 4)
    print solve(150, 15)
