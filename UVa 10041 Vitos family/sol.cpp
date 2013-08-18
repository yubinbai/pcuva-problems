#include <algorithm>
#include <cmath>
#include <stdio.h>
#include <stdlib.h>

using namespace std;
int main()
{
    long int t, r, j, i, midp, d, street[501], mid;

    while (scanf("%ld", &t) == 1)
    {
        for (i = 1; i <= t; i++)
        {
            scanf("%ld", &r);
            for (j = 0; j < r; j++)
                scanf("%ld", &street[j]);
            sort(street, street + r);
            midp = r / 2;
            if (r % 2 == 0)
                mid = (street[midp - 1] + street[midp]) / 2;
            else
                mid = street[midp];
            d = 0;
            for (j = 0; j < r; j++)
                d += abs(street[j] - mid);
            printf("%ld\n", d);
        }
    }
    return 0;
}