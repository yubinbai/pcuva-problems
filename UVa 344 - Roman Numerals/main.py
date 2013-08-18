romanNumbers = ["c", "xc", "l", "xl", "x", "ix", "v", "iv", "i"]
val = [100, 90, 50, 40, 10, 9, 5, 4, 1]


def toRoman(n):
    converted = []
    for i in range(9):
        d, n = divmod(n, val[i])
        for u in range(d):
            converted.append(romanNumbers[i])
    return ''.join(converted)

for i in range(1, 200):
    print(toRoman(i))
