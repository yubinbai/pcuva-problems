#include <stdio.h>
#include <string.h>
#include <math.h>
int main()
{
    double sin1, cos1, l;
    double x1, x2, x3, x4, x;
    double y1, y2, y3, y4, y;
    while (scanf("%lf%lf%lf%lf", &x1, &y1, &x2, &y2) != EOF)
    {
        x = (x1 + x2) / 2;
        y = (y1 + y2) / 2;
        l = sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
        sin1 = (y2 - y1) / l;
        cos1 = (x2 - x1) / l;
        x3 = x - l * sin1 * 0.5;
        y3 = y + l * cos1 * 0.5;
        x4 = x + l * sin1 * 0.5;
        y4 = y - l * cos1 * 0.5;
        printf("%.10lf %.10lf %.10lf %.10lf\n", x3, y3, x4, y4);
    }
    return 0;
}
