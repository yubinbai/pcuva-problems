#include <iostream>

using namespace std;

int main()
{
    int T;
    cin >> T;
    for (int t = 1; t <= T; ++t)
    {
        cout << "Case " << t << ":" << endl;
        int r;
        cin >> r;
        cout << (-r * 45 / 20) << " " << (r * 30 / 20) << endl;
        cout << (r * 55 / 20) << " " << (r * 30 / 20) << endl;
        cout << (r * 55 / 20) << " " << (-r * 30 / 20) << endl;
        cout << (-r * 45 / 20) << " " << (-r * 30 / 20) << endl;
    }
}