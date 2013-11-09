//  假设a、b(a<b)互质，那么gcd(a,b)=1，这样当i循环到a、j循环到b时就会向结果中+1，
//  而i循环到2*a、j循环到2*b时就会向结果中+2（gcd(2*a,2*b)=2）...循环到k*a和k*b时就会向结果中+k。
//  这样实际上引起结果变化的根源就在于各对互质的数，当i、j循环到他们自身或者自身的倍数时就会引起结果的改变，
//  那么我们不妨先将每对互质的数对结果的贡献值算出来，最后将各对互质的数对结果的贡献累加起来就可以了。

//  假设和b互质的数有n个，也就是n对(?,b)（?和b互质），那么在i、j循环到?、b时结果会增加n，
//  循环到(2*?,2*b)时结果就会增加2*n...当i、j循环到k*?、k*b时结果就会增加k*n。
//  那么我们不妨用a[i]记录各种k、b在满足k*b=i时会增加多少结果，那么最后我们要输出的就是a[2]+a[3]+...+a[N]。

//  至于找和b互质的数，就是计算b的欧拉函数的值，然后暴力循环k，并修改对应的a[k*b]即可，整体的复杂度是O(N*logN)的。

#include<stdio.h>
#include<string.h>
#define MAXD 4000010
const int N = 4000000;
typedef long long LL;
int phi[MAXD];
LL a[MAXD];
void prep()
{
    memset(a, 0, sizeof(a));
    for (int i = 1; i <= N; i ++) phi[i] = i;
    for (int i = 2; i <= N; i ++)
    {
        if (phi[i] == i)
        {
            for (int j = i; j <= N; j += i)
                phi[j] = phi[j] / i * (i - 1);
        }
        for (int j = 1; j * i <= N; j ++)
            a[j * i] += j * phi[i];
    }
    for (int i = 1; i <= N; i ++) a[i] += a[i - 1];
}
int main()
{
    prep();
    int n;
    while (scanf("%d", &n), n) printf("%lld\n", a[n]);
    return 0;
}