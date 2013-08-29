#include <cstdio>
using namespace std;

#define ABS(x) ((x) > 0 ? (x) : -(x))

int main()
{
    int h, m, a;
    while (scanf("%d:%d", &h, &m) == 2 && (h || m))
    {
        a = ABS(h * 60 - m * 11);
        if (a > 360)
            a = 720 - a;
        printf("%.3f\n", a * 0.5f);
    }
    return 0;
}