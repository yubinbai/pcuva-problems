import sys
import numpypy as np

sys.stdin = open('input.txt')

while True:
    n, d = map(int, raw_input().split())
    if not n and not d:
        break
    print n ** d
