#include <iostream>
#include <cstdio>
using namespace std;

int g(int x)
{
    if (x / 10 == 0) return (x);
    int sum = 0;
    while (x > 0)
    {
        sum += (x % 10);
        x /= 10;
    }
    return (g(sum));
}

int main()
{
    int n;
    cin >> n;
    while (n)
    {
        cout << g(n) << endl;
        cin >> n;
    }
    return 0;
}


