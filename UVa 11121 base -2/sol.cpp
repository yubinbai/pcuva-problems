#include <iostream>
#include <string>
using namespace std;
string binary(long n)
{
    if (n == -1) return "11";
    if (n == 1) return "1";
    if (n == 0) return "0";
    if (n % 2 == 0)
        return binary(n / -2) + "0";
    return binary((n - 1) / -2) + "1";
}
int main()
{
    int k;
    cin >> k;
    for (int i = 1; i <= k; i++)
    {
        long n;
        cin >> n;
        cout << "Case #" << i << ": " << binary(n) << endl;
    }
    return 0;
}