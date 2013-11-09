#include <stdio.h>
#include <math.h>
void sa ()
{
    double u;
    double v;
    double t;
    scanf ("%lf %lf %lf", &u, &v, &t);
    double a = (v - u) / t;
    double s = (v * v - u * u) / (2 * a);
    printf ("%.3lf %.3lf\n", s, a);
}
void st ()
{
    double u;
    double v;
    double a;
    scanf ("%lf %lf %lf", &u, &v, &a);
    double t = (v - u) / a;
    double s = (v * v - u * u) / (2 * a);
    printf ("%.3lf %.3lf\n", s, t);
}
void vt ()
{
    double u;
    double a;
    double s;
    scanf ("%lf %lf %lf", &u, &a, &s);
    double v = sqrt (pow (u, 2) + 2 * a * s);
    double t = (v - u) / a;
    printf ("%.3lf %.3lf\n", v, t);
}
void ut ()
{
    double v;
    double a;
    double s;
    scanf ("%lf %lf %lf", &v, &a, &s);
    double u = sqrt (pow (v, 2) - 2 * a * s);
    double t = (v - u) / a;
    printf ("%.3lf %.3lf\n", u, t);
}
int main ()
{
    int dataset;
    int cases = 0;
    while ( scanf ("%d", &dataset) && dataset )
    {
        printf ("Case %d: ", ++cases);
        switch (dataset)
        {
        case 1 :
            sa ();
            break;
        case 2 :
            st ();
            break;
        case 3 :
            vt ();
            break;
        case 4 :
            ut ();
            break;
        }
    }
    return 0;
}