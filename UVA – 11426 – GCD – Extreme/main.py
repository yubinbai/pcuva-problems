# 假设a、b(a<b)互质，那么gcd(a,b)=1，这样当i循环到a、j循环到b时就会向结果中+1，
# 而i循环到2*a、j循环到2*b时就会向结果中+2（gcd(2*a,2*b)=2）...循环到k*a和k*b时就会向结果中+k。
# 这样实际上引起结果变化的根源就在于各对互质的数，当i、j循环到他们自身或者自身的倍数时就会引起结果的改变，
# 那么我们不妨先将每对互质的数对结果的贡献值算出来，最后将各对互质的数对结果的贡献累加起来就可以了。

# 假设和b互质的数有n个，也就是n对(?,b)（?和b互质），那么在i、j循环到?、b时结果会增加n，
# 循环到(2*?,2*b)时结果就会增加2*n...当i、j循环到k*?、k*b时结果就会增加k*n。
# 那么我们不妨用a[i]记录各种k、b在满足k*b=i时会增加多少结果，那么最后我们要输出的就是a[2]+a[3]+...+a[N]。

# 至于找和b互质的数，就是计算b的欧拉函数的值，然后暴力循环k，并修改对应的a[k*b]即可，整体的复杂度是O(N*logN)的。

import sys
import math
from multiprocessing import Pool
from collections import Counter


def primeFactors(n):
    '''
    lists prime factors of a natural number, from greatest to smallest
    '''
    i = 2
    result = []
    while i <= math.sqrt(n):
        while n % i == 0:
            result.append(i)
            n /= i
        i += 1
    if n != 1:
        result.append(n)
    result.sort()
    return result


def getAllFactors(n):
    def backtrack(step):
        if step == N:
            aFactor = 1
            for j, p in enumerate(path):
                aFactor *= factors[j] ** p
            result.add(aFactor)
            return
        for i in range(counter[factors[step]] + 1):
            path[step] = i
            backtrack(step + 1)
            path[step] = 0

    counter = Counter(primeFactors(n))
    factors = counter.keys()
    factors.sort()
    N = len(factors)
    path = [0] * N

    result = set()
    backtrack(0)
    result = list(result)
    result.sort()
    return result

# def allFactors(number):
#     result = []
#     for i in range(1, int(math.sqrt(number)) + 1):
#         a, b = divmod(number, i)
#         if b == 0:
#             if i < a:
#                 result.append(i)
#                 result.append(a)
#             else:
#                 if a == i:
#                     result.append(a)
#                 break
#     result.sort()
#     return result


def findn(n):
    factor = getAllFactors(n)
    fCount = [(n - 1) / f for f in factor]
    nF = len(factor) - 1
    for i in reversed(range(nF)):
        for j in range(i):
            if factor[i] % factor[j] == 0:
                fCount[j] -= fCount[i]
    s = sum([factor[i] * fCount[i] for i in range(nF)])
    return s

if __name__ == '__main__':
    MAXN = 400000
    p = Pool(processes=3)
    memo = [0, 0]
    memo += p.map(findn, list(range(2, MAXN)))
    for i in range(1, len(memo)):
        memo[i] += memo[i - 1]
    sys.stdin = open('input.txt')
    while True:
        n = int(input())
        if not n:
            break
        print memo[n]
