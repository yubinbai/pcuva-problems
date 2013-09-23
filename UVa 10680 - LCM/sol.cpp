#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

#define sz(a) int((a).size())

typedef long long llong;

const int MAXN = 1000256;
bool prime[MAXN];
vector<int> P;

void preprocess()
{
    for (int i = 0; i < MAXN; ++i)
        prime[i] = true;
    prime[0] = prime[1] = false;
    for (int i = 2; i < MAXN; ++i)
    {
        if (prime[i])
        {
            P.push_back(i);
            for (int j = i + i; j < MAXN; j += i)
                prime[j] = false;
        }
    }
    swap(P[1], P[2]);
}

int main(int argc, char *argv[])
{
    preprocess();
    int n, res, c2, c5;
    while (1 == scanf("%d", &n))
    {
        if (!n) break;
        res = 1;
        c2 = c5 = 0;
        for (int i = 2; i <= n; i *= 2) c2++;
        for (int i = 5; i <= n; i *= 5) c5++;
        for (int i = 0; i < c2 - c5; ++i) res = (res * 2) % 10;
        for (int i = 2; i < sz(P); ++i)
        {
            if (P[i] > n) break;
            for (llong j = P[i]; j <= n; j *= P[i])
                res = (res * P[i]) % 10;
        }
        printf("%d\n", res);
    }
    return 0;
}