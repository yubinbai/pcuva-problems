inFile = open('input.txt')
primes = [2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37,
          41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97]
for line in inFile:
    n = int(line)
    if n == 0:
        break
    lenPrime = len(primes)
    counter = [0] * lenPrime
    for i in range(1, n + 1):
        number = i
        for i, p in enumerate(primes):
            while number % p == 0:
                counter[i] += 1
                number /= p
    while counter[-1] == 0:
        counter.pop()
    print ('%3d! = ' % n) + ' '.join(str(c) for c in counter)
