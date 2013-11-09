#include <cstdio>
#include <cmath>
using namespace std;
inline long abs(long x)
{
    if (x < 0) return -x;
    return x;
}
long MyGcd(long p, long q)
{
    long m;
    p = abs(p);
    q = abs(q);
    while ( p != 0 )
    {
        m = p;
        p = q % p;
        q = m;
    }
    return q;
}
long arr[60];
int main()
{
    int n;
    int i, j;
    int ct;
    int tot;
    while (1)
    {
        scanf("%d", &n);
        if ( n == 0 ) break;
        for (i = 0; i < n; i++)
            scanf("%ld", &arr[i]);
        ct = 0;
        for (i = 0; i < n - 1; i++)
            for (j = i + 1 ; j < n ; j++)
                if ( MyGcd( arr[i], arr[j] ) == 1) ct++;
        tot = n * (n - 1) / 2;
        if ( ct == 0)
            printf("No estimate for this data set.\n");
        else
            printf("%.6lf\n" , sqrt((double)6 * (double)tot / (double)ct) );
    }
    return 0;
}