#include <iostream>

using namespace std;

int minn;
int dp(int x)
{
    int i, cnt = 0;
    for (i = 1; i <= 10; i++)
        if (((x & (1 << (i - 1))) && (x & (1 << i)) && !(x & (1 << (i + 1)))) || (!(x & (1 << (i - 1))) && (x & (1 << i)) && (x & (1 << (i + 1)))))
        {
            x ^= (1 << (i - 1));
            x ^= (1 << i);
            x ^= (1 << (i + 1));
            int temp = dp(x);
            if (temp < minn) minn = temp;
            x ^= (1 << (i - 1));
            x ^= (1 << i);
            x ^= (1 << (i + 1));
            cnt++;
        }
    if (cnt == 0)
    {
        int ans = 0;
        for (i = 0; i < 12; i++)
            if (x & (1 << i)) ans++;
        if (ans < minn) minn = ans;
    }
    return minn;
}
int main()
{
    char s[15];
    int T, i;
    cin >> T;
    while (T--)
    {
        cin >> s;
        int a = 0;
        for (i = 0; i < 12; i++)
            if (s[i] == 'o') a = a ^ (1 << i);
        minn = (1 << 30);
        cout << dp(a) << endl;
    }
    return 0;
}
