#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;


int main()
{
    char str[11];
    int n, len;
    scanf("%d ", &n);
    while (n--)
    {
        len = strlen(gets(str));
        sort(str, str + len);
        do
        {
            puts(str);
        }
        while (next_permutation(str, str + len));
        putchar('\n');
    }
    return 0;
}