#include<iostream>
#include<cmath>
using namespace std;

int n, m;
int main()
{
    int t;
    cin >> t;
    while (cin >> n >> m)cout << int(ceil((n - 2) / 3.0)*ceil((m - 2) / 3.0)) << endl;
    return 0;
}