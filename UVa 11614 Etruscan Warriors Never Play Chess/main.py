import sys
import math

sys.stdin = open('input.txt')
for _ in range(int(input())):
    a = int(input())
    x = math.floor(0.5 * (math.sqrt(8 * a + 1) - 1))
    print int(x)
