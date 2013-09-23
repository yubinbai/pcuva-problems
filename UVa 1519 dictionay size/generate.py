import random
import sys

f = open('input.txt', 'w')
sys.stdout = f

n = 10
print n

chars = [chr(c) for c in range(ord('a'), ord('z') + 1)]
for i in range(n):
    w = []
    for j in range(40):
        w.append(random.choice(chars))
    print ''.join(w)
