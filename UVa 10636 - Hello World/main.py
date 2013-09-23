import sys
from math import *

sys.stdin = open('input.txt')
while True:
    N = int(input())
    if N == -1:
        break
    print '%d' % ceil(log(N, 2))
