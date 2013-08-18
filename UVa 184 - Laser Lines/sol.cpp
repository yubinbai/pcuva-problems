#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using std::vector;
struct Point
{
    int x, y;
};
int cmpY(const Point &a, const Point &b )
{
    return (a.y < b.y);
}
int cmpX(const Point &a, const Point &b )
{
    return (a.x < b.x);
}
// three points on the same line
bool is_collinear(Point a, Point b, Point c)
{
    int pos = a.x * b.y + b.x * c.y + c.x * a.y;
    int neg = a.x * c.y + b.x * a.y + c.x * b.y;
    return (pos == neg);
}
void output(vector<Point> &line, int is_first_line )
{
    if ( is_first_line )
        puts("The following lines were found:");
    for (int i = 0; i < line.size(); ++i)
        printf("(%4d,%4d)", line[i].x, line[i].y);
    puts("");
}
bool is_prev_exist( Point a, Point b, vector<Point> prev_line )
{
    for (int i = 0; i < prev_line.size(); i = i + 2)
    {
        int r1 = is_collinear(a, b, prev_line[i]);
        int r2 = is_collinear(a, b, prev_line[i + 1]);
        if ( r1 && r2 ) return true;
    }
    return false;
}
void find_all_collinear( vector<Point> &points )
{
    int no_line_found = 1;
    int is_first_line = 1;
    std::stable_sort(points.begin(), points.end(), cmpY);
    std::stable_sort(points.begin(), points.end(), cmpX);
    vector<Point> prev_line;
    for (int i = 0; i < points.size(); ++i)
    {
        for (int j = i + 1; j < points.size(); ++j)
        {
            if ( is_prev_exist(points[i], points[j], prev_line) )
                continue;
            vector<Point> line;
            line.push_back(points[i]);
            line.push_back(points[j]);
            // check line pi-pj
            for (int k = j + 1; k < points.size(); ++k)
            {
                if ( is_collinear(points[i], points[j], points[k]) )
                {
                    no_line_found = 0;
                    line.push_back(points[k]);
                }
            }
            if ( line.size() > 2 )
            {
                output(line, is_first_line);
                is_first_line = 0;
                prev_line.push_back(line[0]);
                prev_line.push_back(line[1]);
            }
        }
    }
    if ( no_line_found )
        puts("No lines were found");
}
int main()
{
    // for each input set
    while (1)
    {
        vector<Point> point_list;
        Point p;
        while ( scanf("%d %d", &p.x, &p.y) == 2 )
        {
            if ( p.x == 0 && p.y == 0) break; // end of point set
            point_list.push_back(p);
        }
        if (point_list.size() == 0) break;
        find_all_collinear( point_list );
    }
    return 0;
}