#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <ctime>
#include <sstream>
using namespace std;
int main()
{
    while (true)
    {
        int N;
        scanf("%d", &N);
        if (!N) break;
        int Sz  = (int)ceil(N / 4.0);
        int Front[Sz][2], Back[Sz][2];
        int A = 1, B = 4 * Sz;
        for (int i = 0; i < Sz; i++)
        {
            if (B <= N) Front[i][0] = B;
            else        Front[i][0] = -1;
            if (A <= N) Front[i][1] = A;
            else        Front[i][1] = -1;
            A += 2; B -= 2;
        }
        A = 2; B = 4 * Sz - 1;
        for (int i = 0; i < Sz; i++)
        {
            if (A <= N) Back[i][0] = A;
            else        Back[i][0] = -1;
            if (B <= N) Back[i][1] = B;
            else        Back[i][1] = -1;
            A += 2; B -= 2;
        }
        printf("Printing order for %d pages:\n", N);
        for (int i = 0; i < Sz; i++)
        {
            if (Front[i][0] > 0 || Front[i][1] > 0)
            {
                printf("Sheet %d, front: ", i + 1);
                if (Front[i][0] > 0) printf("%d, ", Front[i][0]);
                else printf("Blank, ");
                if (Front[i][1] > 0) printf("%d\n", Front[i][1]);
                else printf("Blank\n");
            }
            if (Back[i][0] > 0 || Back[i][1] > 0)
            {
                printf("Sheet %d, back : ", i + 1);
                if (Back[i][0] > 0) printf("%d, ", Back[i][0]);
                else printf("Blank, ");
                if (Back[i][1] > 0) printf("%d\n", Back[i][1]);
                else printf("Blank\n");
            }
        }
    }
    return 0;
}