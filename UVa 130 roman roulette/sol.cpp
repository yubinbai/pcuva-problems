#include <stdio.h>
int queue[105];
void CountRoman(int n, int k)
{
    int i;
    int tot = n;
    int killed , next = -1;
    int ct = 0;
    for (i = 0; i < n; i++)
        queue[i] = i + 1;
    while ( tot > 1 )
    {
        ct = 0;
        while ( ct < k )
        {
            next = ( next + 1 ) % n;
            if ( queue[next] != 0 ) ct++;
        }
        killed = next;
        queue[killed] = 0;
        next--;
        ct = 0;
        while ( ct < k )
        {
            next = ( next + 1 ) % n;
            if ( queue[next] != 0 ) ct++;
        }
        queue[killed] = queue[next];
        queue[next] = 0;
        next = killed;
        tot--;
    }
    i = 0;
    while ( queue[i] == 0) i++;
    printf("%d\n" , (n - queue[i] + 1) % n + 1 );
}
int main()
{
    int n, k;
    while (1)
    {
        scanf("%d %d", &n, &k );
        if ( n == 0 && k == 0 ) break;
        CountRoman(n, k);
    }
    return 0;
}
