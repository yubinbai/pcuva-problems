/*Note:
    num[]——输入数据
    D[i]——num[]中, LIS为i,但结尾元素最大者.
    numPos[i]——D[i]在num[]中的位置，与D[i]一一对应
    pre[i]——前驱数组，负责打印LIS
*/
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
const int maxn = 100000;  //数组之前开10000直接RE，索性10W就AC
vector<int> num, numPos, pre,  D;
vector<int>::iterator it;  //迭代器
int LIS[maxn];  //最后记录LIS
////////////////////////////////////////////
int main()
{
    int temp, numCount = 0;
    while (cin >> temp)
    {
        num.push_back(temp);
        pre.push_back(-1); //默认每个序列前驱不存在，为-1
    }
    //LIS nlog(n)算法实现
    numPos.push_back(0);
    D.push_back(num[0]);
    for (int i = 1; i < num.size(); i++)
    {
        if (num[i] > D.back())
        {
            pre[i] = numPos.back();  
            D.push_back(num[i]);
            numPos.push_back(i);  
        }
        else
        {
            it = lower_bound(D.begin(), D.end(), num[i]); //在D中二分查找num[i]可以插入的位置，并将该位置以迭代器形式返回
            *it = num[i];  //将num[i]插入D中, 更新D
            numPos[it - D.begin()] = i; //D中插入num[i]后，对应记录其在num[]中的原位置
            pre[i] = numPos[it - D.begin() - 1]; //更新前驱

        }
    }
    cout << D.size() << endl << '-' << endl;   //LIS长度
    //注意D.size()返回的是向量数目，所以最后一个元素迭代器应减1
    //k变量为LIS最后一个元素在输入数据中的位置，即numPos[D.size()-1]
    int k = numPos[D.size() - 1];
    //记录LIS并打印
    for (int i = D.size() - 1; i >= 0; i--)
    {
        LIS[i] = num[k];
        k = pre[k];
    }
    for (int i = 0; i < D.size(); i++)
        cout << LIS[i] << endl;

    return 0;
}