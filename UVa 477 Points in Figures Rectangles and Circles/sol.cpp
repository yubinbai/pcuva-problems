#include <iostream>
#include <cmath>
using namespace std;
struct point
{
    double x, y;
};
struct figure
{
    char type;
    point origin;
    union
    {
        double radius;
        point lrc; // lower right corner
    };
};
inline bool is_contained(double x, double y, const figure &f)
{
    if (f.type == 'c')
        return sqrt((x - f.origin.x) * (x - f.origin.x) + (y - f.origin.y) * (y - f.origin.y)) < f.radius;
    // this is rectangle
    return x > f.origin.x && y < f.origin.y && x < f.lrc.x && y > f.lrc.y;
}
int main()
{
    ios::sync_with_stdio(false);
    figure fs[10];
    short count(0);
    char type;
    while (cin >> type)
    {
        if (type == 'c')
        {
            double x, y, r;
            cin >> x >> y >> r;
            figure &f = fs[count++];
            f.type = type;
            f.origin.x = x;
            f.origin.y = y;
            f.radius = r;
        }
        else if (type == 'r')
        {
            double x, y, dx, dy;
            cin >> x >> y >> dx >> dy;
            figure &f = fs[count++];
            f.type = type;
            f.origin.x = x;
            f.origin.y = y;
            f.lrc.x = dx;
            f.lrc.y = dy;
        }
        else break;
    }
    double x, y;
    int point(0);
    while (cin >> x >> y)
    {
        if (x == 9999.9 && y == 9999.9) break;
        ++point;
        bool contained = false;
        for (short i(0); i < count; ++i)
        {
            if (is_contained(x, y, fs[i]))
            {
                cout << "Point " << point << " is contained in figure " << i + 1 << "\n";
                contained = true;
            }
        }
        if (!contained) cout << "Point " << point << " is not contained in any figure\n";
    }
    return 0;
}