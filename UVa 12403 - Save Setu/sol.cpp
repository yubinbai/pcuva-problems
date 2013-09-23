#include <cstdio>
#include <cstring>
using namespace std;
int main ()
{
    int testCase; scanf ("%d", &testCase);
    char input [100];
    int totalAmount = 0;
    int inputAmount;
    while ( testCase-- )
    {
        scanf ("%s", input);
        if ( strcmp (input, "donate") == 0 )
        {
            scanf ("%d", &inputAmount);
            totalAmount += inputAmount;
        }
        else
        {
            printf ("%d\n", totalAmount);
        }
    }
    return 0;
}
