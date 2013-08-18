#include <algorithm>
#include <iostream>
#include <iterator>
#include <string>
#include <vector>
using namespace std;
//主函数
int main(void)
{
    //循环处理输入的每组朋友圈
    for (int nPeople, nFirst = 1; cin >> nPeople; nFirst = 0)
    {
        //vecName按顺序存储各人姓名，vecWorth为各人净收入
        vector<string> vecName(nPeople);
        vector<int> vecWorth(nPeople, 0);
        //输入所有人的姓名
        for (int i = 0; i < nPeople; cin >> vecName[i++]);
        //循环处理每个人的收支
        for (int i = 0, nMoney, nFriCnt; i < nPeople; ++i)
        {
            //读入姓名，金额和朋友数
            string strName;
            cin >> strName >> nMoney >> nFriCnt;
            //找到此人在数组中的位置
            vector<string>::iterator iPeople = find(vecName.begin(), vecName.end(), strName);
            int &nCurWorth = vecWorth[distance(vecName.begin(), iPeople)];
            //从此人净收入中支出金额分平均分给朋友
            nCurWorth -= nMoney;
            if (nFriCnt > 0)
            {
                //平分到每个朋友的净收入中
                for (int j = 0, nShare = nMoney / nFriCnt; j < nFriCnt; ++j)
                {
                    //找到朋友在数组中的位置，并加入到净收入中
                    cin >> strName;
                    iPeople = find(vecName.begin(), vecName.end(), strName);
                    vecWorth[distance(vecName.begin(), iPeople)] += nShare;
                }
                //计算平分后剩下的零头
                nMoney %= nFriCnt;
            }
            //如果剩有零头或未分给任何朋友，则返回净收入
            nCurWorth += nMoney;
        }
        //按照要求，每组输出间要以空行隔开，但第一组前面不能有空行
        cout << (nFirst == 1 ? "" : "\n");
        //按顺序输出结果，每行前面是姓名，后面是净收入，用空格隔开
        for (int i = 0; i != vecName.size(); ++i)
        {
            cout << vecName[i] << ' ' << vecWorth[i] << endl;
        }
    }
    return 0;
}