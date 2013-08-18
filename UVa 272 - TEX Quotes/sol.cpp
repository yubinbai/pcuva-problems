#include <cstdio>


using namespace std;

int main()
{
    char c;
    bool ax = 1;

    while (scanf("%c", &c) != EOF)
    {
        if (c == '"')
        {
            if (ax) printf("``");
            else printf("''");

            ax = (!ax);
        }
        else printf("%c", c);
    }

    return 0;
}