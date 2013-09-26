#include <iostream>
using namespace std;
int countOnes(int d)
{
    int count = 0;
    while (d > 0)
    {
        if (d % 2 == 1) count++;
        d /= 2;
    }
    return count;
}
int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        int d;
        cin >> d;
        cout << countOnes(d);
        int count = 0;
        while (d > 0)
        {
            int last = d % 10;
            count += countOnes(last);
            d /= 10;
        }
        cout << " " << count << endl;
    }
}