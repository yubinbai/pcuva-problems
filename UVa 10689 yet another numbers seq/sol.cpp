#include <iostream>
#include <vector>
using namespace std ;
const int MaxM = 4 ;
int m = 0 ;
int pow10s[MaxM + 1] = { 0 } ;
vector<int> mul(const vector<int> &a, const vector<int> &b)
{
    vector<int> ret(4, 0) ;
    ret[0] = (a[0] * b[0] + a[1] * b[2]) % pow10s[m] ;
    ret[1] = (a[0] * b[1] + a[1] * b[3]) % pow10s[m] ;
    ret[2] = (a[2] * b[0] + a[3] * b[2]) % pow10s[m] ;
    ret[3] = (a[2] * b[1] + a[3] * b[3]) % pow10s[m] ;
    return ret ;
}
vector<int> pow(const vector<int> &v, long long int p)
{
    vector<int> ret ;
    if (p == 0)
    {
        ret.assign(4, 0) ;
        ret[0] = 1 ;
        ret[3] = 1 ;
        return ret ;
    }
    else if (p == 1)
    {
        return v ;
    }
    else
    {
        ret = pow(v, p / 2) ;
        ret = mul(ret, ret) ;
        if (p % 2 == 1)
        {
            ret = mul(ret, v) ;
        }
        return ret ;
    }
}
int main()
{
    int a = 0 ;
    int b = 0 ;
    long long int n = 0 ;
    vector<int> fibonacci ;
    vector<int> resultMatrix ;
    int casenum = 0 ;
    int i = 0 ;
    pow10s[0] = 1 ;
    for (i = 1 ; i <= MaxM ; i++)
        pow10s[i] = pow10s[i - 1] * 10 ;
    fibonacci.assign(4, 0) ;
    fibonacci[0] = 0 ;
    fibonacci[1] = 1 ;
    fibonacci[2] = 1 ;
    fibonacci[3] = 1 ;
    cin >> casenum ;
    for (i = 1 ; i <= casenum ; i++)
    {
        cin >> a >> b >> n >> m ;
        resultMatrix = pow(fibonacci, n) ;
        cout << (resultMatrix[0] * a + resultMatrix[1] * b) % pow10s[m] << endl ;
    }
    return 0 ;
}