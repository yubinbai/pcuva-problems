#include<iostream>
using namespace std;
int main()
{
    long long n = 0;
    cin >> n;
    while (n > -1)
    {
        cout << (n * (n + 1) / 2) + 1 << endl;
        cin >> n;
    }
    return 0;
}
