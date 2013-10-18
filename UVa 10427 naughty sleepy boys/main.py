import sys
import bisect

sys.stdin = open('input.txt')
digits = [0]
i = 1
while digits[-1] < 100000000:
    digits.append(digits[-1] + i * 9 * 10 ** (i - 1))
    i += 1

while True:
    try:
        n = int(input())
    except:
        break
    idx = bisect.bisect_left(digits, n)
    x = n - digits[idx - 1]
    # print idx, (x - 1) // idx + 1, (x - 1) % idx
    print str(10 ** (idx - 1) + (x - 1) // idx)[(x - 1) % idx]
