#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <stdlib.h>
#include <cmath>
#include <string.h>

using namespace std;

typedef double coord_t;
typedef double coord2_t;


class Point {
public:
    coord_t x, y;
    Point () {
        x = 0;
        y = 0;
    }
    Point (coord_t tx, coord_t ty) {
        x = tx;
        y = ty;
    }
    bool operator <(const Point &p) const {
        return x < p.x || x == p.x && y < p.y;
    }
};

double R;
int n;
vector<Point> points;


inline coord2_t cross(const Point &O, const Point &A, const Point &B) {
    return (A.x - O.x) * (B.y - O.y) - (A.y - O.y) * (B.x - O.x);
}

vector<Point> convex_hull(vector<Point> P) {
    int n = P.size(), k = 0;
    vector<Point> H(2 * n);
    sort(P.begin(), P.end());
    for (int i = 0; i < n; ++i) {
        while (k >= 2 && cross(H[k - 2], H[k - 1], P[i]) <= 0) k--;
        H[k++] = P[i];
    }
    for (int i = n - 2, t = k + 1; i >= 0; --i) { // The point with index n - 1 is already in H
        while (k >= t && cross(H[k - 2], H[k - 1], P[i]) <= 0) k--;
        H[k++] = P[i];
    }
    H.resize(k - 1);
    return H;
}

int fsig(double x) {
    if (fabs(x) < 1e-6) {
        return 0;
    }
    if (x > 0) {
        return 1;
    } else {
        return -1;
    }
}

int fcmp (double x, double y) {
    return fsig(x - y);
}

inline double sqr (double x) {
    return x * x;
}

inline double sqr_dis (Point a, Point b) {
    return sqr(b.x - a.x) + sqr(b.y - a.y);
}

int is_center (Point p) {
    for (int i = 0; i < n; ++i) {
        if (fcmp(sqr_dis(points[i], p), R * R) > 0) {
            return 0;
        }
    }
    return 1;
}

int check (Point a, Point b) {
    double x1 = a.x, x2 = b.x, y1 = a.y, y2 = b.y;
    double q = sqrt(sqr_dis(a, b));
    if (fcmp(q * q, 4 * R * R) > 0) {
        return 0;
    }
    double x_part = sqrt(R * R - 0.25 * q * q) * (y1 - y2) / q;
    double y_part = sqrt(R * R - 0.25 * q * q) * (x2 - x1) / q;
    double x3 = 0.5 * (x1 + x2), y3 = 0.5 * (y1 + y2);
    Point p1 = Point(x3 + x_part, y3 + y_part);
    Point p2 = Point(x3 - x_part, y3 - y_part);
    return is_center(p1) || is_center(p2);
}

int is_satisfied (void) {
    if (n == 1) {
        return 1;
    } else if (n == 2) {
        return sqr_dis(points[0], points[1]) <= 4 * R * R;
    } else {
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (check(points[i], points[j])) {
                    return 1;
                }
            }
        }
        return 0;
    }
}

int main() {
        while (scanf("%d", &n)) {
        if (!n) {
            break;
        }
        points.clear();
        for (int i = 0, x, y; i < n; ++i) {
            scanf("%d%d", &x, &y);
            points.push_back(Point(x, y));
        }
        scanf("%lf", &R);
        printf(is_satisfied() ? "The polygon can be packed in the circle.\n" : "There is no way of packing that polygon.\n");
    }
    return 0;
}
