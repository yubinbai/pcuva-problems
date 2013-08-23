#include<stdio.h>
using namespace std;
#define SWAP(a,b) a= a^b, b=a^b, a=a^b
int main()
{
    int o, reverse;
    while (scanf("%d", &o) == 1)
    {
        reverse = o;
        char *bits = (char *) &reverse;
        SWAP(bits[0], bits[3]), SWAP(bits[1], bits[2]);
        printf("%d converts to %d\n", o, reverse);
    }
    return 0;
}