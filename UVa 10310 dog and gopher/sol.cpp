#include <stdio.h>
#include <math.h>
typedef  struct
{
    double x;
    double y;
} point;
double pDistance(point p1, point p2)
{
    return sqrt(pow(p1.x - p2.x, 2.0) + pow(p1.y - p2.y, 2.0));
}
int main()
{
    int holes, boo, i, escape;
    point gopher, dog, hole;
    boo = scanf("%d ", &holes);
    while (boo != EOF)
    {
        scanf("%lf %lf %lf %lf\n", &gopher.x, &gopher.y, &dog.x, &dog.y);
        escape = 0;
        for (i = 0; i < holes; i++)
        {
            scanf("%lf %lf", &hole.x, &hole.y);
            if (escape == 1) continue;
            if (pDistance(dog, hole) / 2.0 >= pDistance(gopher, hole))
            {
                escape = 1;
                printf("The gopher can escape through the hole at (%.3f,%.3f).\n", hole.x, hole.y);
            }
        }
        if (escape == 0)
        {
            printf("The gopher cannot escape.\n");
        }
        boo = scanf("\n%d", &holes);
    }
    return 0;
}
