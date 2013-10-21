#include<iostream>
using namespace std;
long long f91(long long a);
int main()
{
    long long N = 0;
    for (;;)
    {
        cin >> N;
        if (N == 0)
            break;
        cout << "f91(" << N << ") = " << f91(N) << endl;
    }
    return 0;
}
long long f91(long long a)
{
    if (a >= 101)
        return (a - 10);
    else
        return f91(f91(a + 11));
}