#include<iostream>
using namespace std;
int main()
{
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        int ctr = 1, sum = 0;
        while (a > 0)
        {
            int rem = a % 10;
            if (ctr % 2 == 0)
            {
                rem *= 2;
            }
            sum += rem % 10 + rem / 10;
            a /= 10;
            ctr++;
        }
        ctr = 1;
        while (b > 0)
        {
            int rem = b % 10;
            if (ctr % 2 == 0)
            {
                rem *= 2;
            }
            sum += rem % 10 + rem / 10;
            b /= 10;
            ctr++;
        }
        ctr = 1;
        while (c > 0)
        {
            int rem = c % 10;
            if (ctr % 2 == 0)
            {
                rem *= 2;
            }
            sum += rem % 10 + rem / 10;
            c /= 10;
            ctr++;
        }
        ctr = 1;
        while (d > 0)
        {
            int rem = d % 10;
            if (ctr % 2 == 0)
            {
                rem *= 2;
            }
            sum += rem % 10 + rem / 10;
            d /= 10;
            ctr++;
        }
        if (sum % 10 == 0)
            cout << "Valid" << endl;
        else
            cout << "Invalid" << endl;
    }
    return 0;
}