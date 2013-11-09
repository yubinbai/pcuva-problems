#include <cstdio>
using namespace std;

#define R(d) ( ((d) & 0x000F00) << 12 | ((d) & 0x00000F) << 16 | ((d) & 0x00F0F0) | ((d) & 0x0F0000) >> 8 | ((d) & 0xF00000) >> 20 )
#define F(d) ( ((d) & 0x0000F0) << 16 | ((d) & 0x00F000) << 4 | ((d) & 0xF00000) >> 8 | ((d) & 0x000F0F) | ((d) & 0x0F0000) >> 12 )

bool E(long long d1, long long d2)
{
    return ((d1) == (d2) || (d1) == R((d2)) || (d1) == R(R((d2))) || (d1) == R(R(R((d2)))));
}

char ans[2][16] = { "Not Equal", "Equal" };

int main()
{
    long long t, d1, d2;
    scanf("%lld", &t);
    while (t--)
    {
        bool out = false;
        scanf("%llx %llx", &d1, &d2);
        out = E(d1, d2) || E(d1, F(d2)) || E(d1, F(F(d2))) || E(d1, F(F(F(d2))))
              || E(d1, F(R(d2))) || E(d1, F(R(R(R(d2)))));
        printf("%s\n", ans[out]);
    }
    return 0;
}