factorial = [0] * 600

a = 1
for i in range(1, 500 + 1):
    a *= i
    factorial[i] = a

print factorial
f = open('input.txt')
for line in f:
    n = int(line)
    print(line.strip() + '!')
    print(factorial[n])
