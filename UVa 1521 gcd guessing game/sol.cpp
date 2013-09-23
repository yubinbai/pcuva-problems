#include<cstdio>
#include<cstring>
#include<algorithm>
#include<functional>
#include<iostream>
#include<cstdlib>
#include<cmath>
using namespace std;
#define MAXN (10000)
#define eps (1e-9)
#define For(i,n) for(int i=1;i<=n;i++)
#define ForD(i,n) for(int i=n;i;i--)
#define Fork(i,k,n) for(int i=k;i<=n;i++)
int n, a[MAXN], size = 0;
bool b[MAXN];
int main()
{
    memset(b, 0, sizeof(b)); b[1] = 1;
    Fork(i, 2, MAXN)
    {
        if (!b[i])
            b[i] = 1, a[++size] = i;
        For(j, size)
        {
            if (i * a[j] > MAXN) break;
            b[i * a[j]] = 1;
            if (!i % a[j]) break;
        }
    }
    while (cin >> n)
    {
        int i = 0, head = 1, tail = size;
        while (a[tail] > n) tail--;
        while (head <= tail)
        {
            int p = a[tail];
            while (p * a[head] <= n)
                p *= a[head++];
            tail--; i++;
        }
        cout << i << endl;
    }
    return 0;
}