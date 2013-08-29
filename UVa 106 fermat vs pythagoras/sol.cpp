#include <iostream>
#include <math.h>
using namespace std;
//主函数
int main(void)
{
    //以下算法的描述详见相关文档
    //循环处理所有输入的N，变量i表示N
    for (int i, m, n, nMaxM, nMaxN, nCnt = 0; cin >> i; nCnt = 0)
    {
        //aFlags用于标记哪些整数在三元组中出现过
        bool aFlags[1000001] = {false};
        //循环生成所有的m和n，根据公式，m的最大值必小于N的开平方
        for (m = 2, nMaxM = (int)sqrt((float)i - 1); m <= nMaxM; ++m)
        {
            //求出n的最大值，小于等于m，且小于等于i-m^2
            nMaxN = (int)sqrt((float)i - m * m);
            nMaxN = nMaxN >= m ? m - 1 : nMaxN;
            //此时已得到所有可能的m和n的范围，循环生成所有三元组
            for (n = 1; n <= nMaxN; ++n)
            {
                //n和m必须互质，忽略都是偶数的情况
                if (n % 2 != m % 2)
                {
                    //进一步判断互质，辗转相除法求出n和m的最大公因数
                    int a = m, b = n, c;
                    for (int r; (r = a % b) != 0; a = b, b = r);
                    //公因数为1才互质
                    if (b == 1)
                    {
                        //生成了一个互质三元组，总数增1
                        ++nCnt;
                        //根据此三元组，生成所有并不互质的三元组，
                        a = m * m - n * n, b = 2 * m * n, c = m * m + n * n;
                        //标记在这些三元组中出现的整数
                        for (int k = 0; c * k <= i; ++k)
                        {
                            aFlags[a * k] = aFlags[b * k] = aFlags[c * k] = 1;
                        }
                    }
                }
            }
        }
        //输出三元组的数量
        cout << nCnt << ' ';
        //统计并输出没有使用过的整数(p)的数量
        for (nCnt = 0, m = 1; m <= i; nCnt += !aFlags[m++]);
        cout << nCnt << endl;
    }
    return 0;
}