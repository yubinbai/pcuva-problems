#include <iostream>
#include <cstdlib>
#include <cstdio>

using namespace std;

typedef struct pnode
{
    double x, y;
} point;

typedef struct rnode
{
    point p1, p2;
} rect;
rect R[11];

int main()
{
    char c;
    int  count = 0, t = 1;
    while ( cin >> c && c != '*' )
    {
        cin >> R[count].p1.x >> R[count].p1.y
            >> R[count].p2.x >> R[count].p2.y;
        count ++;
    }

    point p;
    while ( cin >> p.x >> p.y )
    {
        if ( p.x == 9999.9 && p.y == 9999.9 ) break;
        int flag = 0;
        for ( int i = 0 ; i < count ; ++ i )
            if ( R[i].p1.x < p.x && R[i].p2.x > p.x &&
                    R[i].p2.y < p.y && R[i].p1.y > p.y )
            {
                flag = 1;
                printf("Point %d is contained in figure %d\n", t, i + 1);
            }
        if ( !flag )
            printf("Point %d is not contained in any figure\n", t);
        t ++;
    }

    return 0;
}
