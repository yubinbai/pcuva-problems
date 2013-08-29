#include <stdio.h>
#include <math.h>

int main()
{
    double m1, m2, m3;
    while (scanf("%lf %lf %lf", &m1, &m2, &m3) == 3)
    {
        double s = (m1 + m2 + m3) / 2.0;
        double area = (4.0 / 3.0) * sqrt(s * (s - m1) * (s - m2) * (s - m3));
        if (!(area > 0))
        {
            area = -1.0;
        }
        printf("%.3lf\n", area);
    }
    return 0;
}