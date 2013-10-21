// 思路: 使正六面体保持不变的运动群总共有:

// 1.不变置换(1)(2)(3)(4)(5)(6), 共1个;

// 2.沿对面中心轴旋转 90度, 270度 (1)(2345)(6), (1)(5432)(6) 同类共 6个;

// 3.沿对面中心轴旋转 180度 (1)(24)(35)(6), 同类共 3个;

// 4.沿对角线轴旋转 120度, 240度 (152)(346), (251)(643) 同类共 8个;

// 5.沿对边中点轴旋转 180度 (16)(25)(43) 同类共 6个;

#include <cstdio>
#include <iostream>
using namespace std;
int N, M;
typedef long long LL;
LL power(int a, int b)
{
    LL res = 1, t = a;
    while (b)
    {
        if (b & 1)res *= t;
        t *= t;
        b >>= 1;
    }
    return res;
}

int main()
{
    int n;
    while (scanf("%d", &n) != EOF && n)
    {
        LL ans = 0;
        ans += power(n, 6);
        ans += 3 * power(n, 4);
        ans += 12 * power(n, 3);
        ans += 8 * power(n, 2);
        ans /= 24;
        printf("%lld\n", ans);

    }
}