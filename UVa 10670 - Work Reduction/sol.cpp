#include <cstdio>
#include <cstring>
#include <cstdlib>

const int MAXN = 110;

struct worker
{
    char name[20];
    int A, B;
    int cost;
};

int N, M, L;
worker W[MAXN];

int cmp( const void *a, const void *b )
{
    worker *c = ( worker * )a;
    worker *d = ( worker * )b;
    if ( c->cost != d->cost ) return c->cost - d->cost;
    else return strcmp( c->name, d->name );
}

void solve( int i )
{
    int a = N;
    int sum = 0;
    while ( a != M )
    {
        //   printf("a=%d\n", a);
        if ( a / 2 >= M && ( a / 2 ) * W[i].A > W[i].B )
        {
            a /= 2;
            sum += W[i].B;
        }
        else
        {
            --a;
            sum += W[i].A;
        }
    }
    W[i].cost = sum;
    return;
}

int main()
{
    int T, tt = 0;
    char temp[20];
    char ch;
    scanf( "%d", &T );
    while ( T-- )
    {
        scanf( "%d%d%d", &N, &M, &L );
        for ( int i = 0; i < L; i++ )
        {
            getchar();
            int k = 0;
            while ( ch = getchar(), ch != ':' )
                temp[k++] = ch;
            temp[k] = '\0';
            strcpy( W[i].name, temp );
            scanf( "%d, %d", &W[i].A, &W[i].B );
            solve(i);
        }

        qsort( W, L, sizeof(W[0]), cmp );

        printf( "Case %d\n", ++tt );
        for ( int i = 0; i < L; i++ )
            printf( "%s %d\n", W[i].name, W[i].cost );
    }
    return 0;
}