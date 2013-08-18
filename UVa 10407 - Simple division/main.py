def gcd(m, n):  # find the greatest common divisor
    if m < n:
        m, n = n, m
    while n:
        m, n = n, m % n
    return m


def solve(row):
    N = len(row)
    row1 = []
    for i in range(1, N):
        if row[i] != row[i - 1]:
            row1.append(abs(row[i] - row[i - 1]))
    g = row1[0]
    for e in row1:
        g = gcd(g, e)
    return g


inFile = open('input.txt')
for line in inFile:
    row = map(int, line.split())
    if row[0] == 0:
        break
    row.pop()
    print(solve(row))
