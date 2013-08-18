#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std;

int hotel[ 10005 ];
int times[ 10005 ];
int Sleep[ 10005 ];

typedef struct dnode
{
    int id;
    int hotel;
    int time;
    dnode( int i, int h, int t)
    {
        id = i; hotel = h; time = t;
    }
    dnode() {}
} dnode;

int cmp( dnode a, dnode b )
{
    if ( a.hotel == b.hotel )
        return a.time - b.time;
    return a.hotel - b.hotel;
}

typedef struct lnode
{
    int    time;
    int    point;
    lnode *next;
} lnode;
lnode *head[ 10005 ];
lnode  edge[ 200005 ];
int    e_count = 0;

void addlist( int a, int b, int t )
{
    edge[ e_count ].next  = head[ a ];
    edge[ e_count ].point = b;
    edge[ e_count ].time  = t;
    head[ a ] = &edge[ e_count ++ ];
}

class heap
{
private:
    int   size;
    dnode *data;
public:
    heap()
    {
        size = 0;
        data = new dnode[ 20005 ];
        memset( data, 0, sizeof( data ) );
    }
    ~heap()
    {
        delete [] data;
    }
    int empty()
    {
        return size == 0;
    }
    void Insert( dnode node )
    {
        data[ ++ size ] = node;
        int now = size;
        while ( now > 1 && cmp( data[ now ], data[ now >> 1 ] ) < 0 )
        {
            swap( data[ now ], data[ now >> 1 ] );
            now = now >> 1;
        }
    }
    dnode Delete()
    {
        swap( data[ 1 ], data[ size ] );
        int now = 1;
        while ( 1 )
        {
            int New = now, L = now << 1, R = (now << 1) + 1;
            if ( L < size && cmp( data[ L ], data[ New ] ) < 0 ) New = L;
            if ( R < size && cmp( data[ R ], data[ New ] ) < 0 ) New = R;
            if ( New == now ) break;
            swap( data[ New ], data[ now ] );
            now = New;
        }
        return data[ size -- ];
    }
};

int spfa( int s, int e, int n )
{
    for ( int i = 1 ; i <= n ; ++ i )
    {
        Sleep[ i ] = -1;
        times[ i ] = -1;
    }
    heap Heap;
    Heap.Insert( dnode(s, 0, 0) );
    while ( !Heap.empty() )
    {
        dnode now = Heap.Delete();
        if ( now.id == e ) return now.hotel;
        for ( lnode *p = head[ now.id ] ; p ; p = p->next )
        {
            int t = now.time + p->time;
            if ( Sleep[ p->point ] < now.hotel )
            {
                Sleep[ p->point ] = now.hotel;
                times[ p->point ] = 601;
            }
            if ( times[ p->point ] > t && hotel[ p->point ] )
            {
                times[ p->point ] = t;
                Heap.Insert( dnode(p->point, now.hotel, t) );
                if ( hotel[ p->point ] == 1 )
                {
                    hotel[ p->point ] = 0;
                    Heap.Insert( dnode(p->point, now.hotel + 1, 0) );
                }
            }
        }
    }
    return -1;
}

int main()
{
    int n, h, c, m, a, b, t;
    while ( scanf("%d", &n) && n )
    {
        scanf("%d", &h);
        memset( hotel, -1, sizeof( hotel ) );
        for ( int i = 1 ; i <= h ; ++ i )
        {
            scanf("%d", &c);
            hotel[ c ] = 1;
        }

        memset( head, 0, sizeof( head ) );
        e_count = 0;
        scanf("%d", &m);
        for ( int i = 1 ; i <= m ; ++ i )
        {
            scanf("%d%d%d", &a, &b, &t);
            addlist( a, b, t );
            addlist( b, a, t );
        }

        printf("%d\n", spfa( 1, n, n ));
    }
    return 0;
}