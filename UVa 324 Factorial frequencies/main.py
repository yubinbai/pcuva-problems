from collections import *

factorial = [1] * 600

a = 1
for i in range(1, 500 + 1):
    a *= i
    factorial[i] = a

f = open('input.txt')
for line in f:
    n = int(line)
    if n != 0:
        print(line.strip() + '!' + ' --')
        print(Counter(str(factorial[n])))
