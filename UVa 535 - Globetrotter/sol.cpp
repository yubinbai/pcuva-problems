#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
#define PI 3.141592653589793
#define R 6378
#define DEG 180.0

struct town
{
    string name;
    double longitude;
    double latitude;
};
double spherical_distance(double lat1, double lon1, double lat2, double lon2)
{
    double dlon = lon2 - lon1;
    double dlat = lat2 - lat1;
    double a = pow((sin(dlat / 2)), 2) + cos(lat1) * cos(lat2) * pow(sin(dlon / 2), 2);
    double c = 2 * atan2(sqrt(a), sqrt(1 - a));
    double d = R * c;
    return d;
}
int main()
{
    town city[200];
    int n = 0, i = 0;
    for (;;)
    {
        cin >> city[n].name;
        if (city[n].name == "#")
            break;
        cin >> city[n].latitude;
        cin >> city[n].longitude;
        city[n].latitude = (PI * city[n].latitude) / DEG;
        city[n].longitude = (PI * city[n].longitude) / DEG;
        n++;
    }
    for (;;)
    {
        string source, destination;
        cin >> source >> destination;
        if (source == "#" && destination == "#")
            break;
        cout << source << " - " << destination << endl;
        double p_lat, p_long, q_lat, q_long;
        int ctr1 = 0, ctr2 = 0;
        for (i = 0; i < n; i++)
        {
            if (source == city[i].name)
            {
                p_long = city[i].longitude;
                p_lat = city[i].latitude;
                ctr1 = 1;
                break;
            }
        }
        if (ctr1 == 0)
        {
            cout << "Unknown" << endl;
            continue;
        }
        for (i = 0; i < n; i++)
        {
            if (destination == city[i].name)
            {
                q_long = city[i].longitude;
                q_lat = city[i].latitude;
                ctr2 = 1;
                break;
            }
        }
        if (ctr2 == 0)
        {
            cout << "Unknown" << endl;
            continue;
        }
        if (source == destination)
        {
            cout << "0 km" << endl;
            continue;
        }
        double distance = spherical_distance(p_lat, p_long, q_lat, q_long);
        int dis = (int)round(distance);
        cout << dis << " km" << endl;
    }

}