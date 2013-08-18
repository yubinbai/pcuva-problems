#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <cctype>
#include <stack>
#include <queue>
#include <list>
#include <vector>
#include <map>
#include <sstream>
#include <cmath>
#include <bitset>
#include <utility>
#include <set>
#include <numeric>
#define INT_MAX 2147483647
#define INT_MIN -2147483647
#define pi acos(-1.0)
#define N 1000000
#define LL unsigned long long
using namespace std;

struct cell
{
    int val;
    int child;
} matrix [10 + 3] [100 + 3];
int row, col;

void reset ()
{
    for ( int i = 0; i < row; i++ )
    {
        for ( int j = 0; j < col; j++ )
            matrix [i] [j].child = -1;
    }
}

int main ()
{
    while ( scanf ("%d %d", &row, &col) != EOF )
    {

        reset ();

        for ( int i = 0; i < row; i++ )
        {
            for ( int j = 0; j < col; j++ ) scanf ("%d", &matrix [i] [j].val);
        }

        for ( int j = col - 2; j >= 0; j-- )
        {
            for ( int i = 0; i < row; i++ )
            {
                int thisNum = matrix [i] [j].val;

                matrix [i] [j].val = thisNum + matrix [(row + i - 1) % row] [j + 1].val;
                matrix [i] [j].child = (row + i - 1) % row;

                int sum = thisNum + matrix [i] [j + 1].val;
                if ( sum < matrix [i] [j].val )
                {
                    matrix [i] [j].val = sum;
                    matrix [i] [j].child = i;
                }
                else if ( sum == matrix [i] [j].val && matrix [i] [j].child > i ) matrix [i] [j].child = i;

                sum = thisNum + matrix [(row + i + 1) % row] [j + 1].val;
                if ( sum < matrix [i] [j].val )
                {
                    matrix [i] [j].val = sum;
                    matrix [i] [j].child = (row + i + 1) % row;
                }
                else if ( sum == matrix [i] [j].val && matrix [i] [j].child > (row + i + 1) % row ) matrix [i] [j].child = (row + i + 1) % row;
            }
        }

        int lowest = INT_MAX;
        int lowest_row;

        for ( int i = 0; i < row; i++ )
        {
            if ( matrix [i] [0].val < lowest )
            {
                lowest = matrix [i] [0].val;
                lowest_row = i;
            }
        }

        vector <int> path;

        for ( int i = 0; i < col; i++ )
        {
            path.push_back (lowest_row + 1);
            lowest_row = matrix [lowest_row] [i].child;
        }

        bool space = false;
        for ( size_t i = 0; i < path.size (); i++ )
        {
            if ( space ) printf (" ");
            space = true;
            cout << path [i];
        }
        cout << endl;
        cout << lowest << endl;
    }

    return 0;
}

