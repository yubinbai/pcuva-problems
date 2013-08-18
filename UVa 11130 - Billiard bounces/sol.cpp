#include <cstdio>
#include <cmath>

using namespace std;

int main()
{
    double a, b, v, ang, s, dist;
    double distH, distV;
    int hitsH, hitsV;
    const double PI = acos(-1);
    while (scanf("%lf %lf %lf %lf %lf", &a, &b, &v, &ang, &s))
    {
        if (a == 0 && b == 0 && v == 0 && ang == 0 && s == 0) break;
        dist = v * s / 2;
        distH = dist * cos((ang / 180.0) * PI);
        distV = dist * sin((ang / 180.0) * PI);
        hitsH = 0; hitsV = 0;
        if (distH > a / 2) hitsH = 1 + int((distH - (a / 2)) / a);
        if (distV > b / 2) hitsV = 1 + int((distV - (b / 2)) / b);
        printf("%d %d\n", hitsH, hitsV);
    }
    return 0;
}