#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
using namespace std;
#define FOI(i, A, B) for(i=A; i<=B; i++)
#define FOD(i, A, B) for(i=A; i>=B; i--)
double toDouble(string s)
{
    stringstream ss(s);
    double D;
    ss >> D;
    return D;
}
int main()
{
    double last = 0.0;
    double dis = 0.0, speed = 0.0;
    string temp;
    while ( getline(cin, temp) )
    {
        stringstream ss(temp);
        string str = "", s = "";
        ss >> str >> s;
        double curr  = ( (str[0] - '0') * 10 + (str[1] - '0') ) / 1.0;
        curr += ( (str[3] - '0') * 10 + (str[4] - '0') ) / 60.0;
        curr += ( (str[6] - '0') * 10 + (str[7] - '0') ) / 3600.0;
        dis  += ( speed * (curr - last) );
        last = curr;
        if ( s == "" )
            printf("%s %2.2lf km\n", str.c_str(), dis);
        else
            speed = toDouble(s);
    }
    return 0;
}