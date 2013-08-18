#include <algorithm>
#include <iostream>
#include <string>
using namespace std;
//主函数
int main(void)
{
    //aMat为连通路口的邻接矩阵，aIdHash为路口字母与其编号的对应表
    //nNodeCnt为路口数量，nRout为最小路径长度
    int aMat[26][26], aIdHash[26], nNodeCnt = 0, nRout = 0, nInf = 0xFFFFFF;
    fill(&aMat[0][0], &aMat[26][0], nInf);
    fill(&aIdHash[0], &aIdHash[26], nInf);
    //循环处理每一行输入，结束时将nRout清0
    for (string strName; cin >> strName;)
    {
        //如果街名为结束符，则按前一阶段的输入数据进行运算
        if (strName == "deadend")
        {
            //aOdd数组用于记录奇顶点，pOdd是aOdd的指针形式
            int aOdd[2] = {0, 0}, *pOdd = &aOdd[0];
            for (int i = 0; i < nNodeCnt && pOdd != &aOdd[2]; ++i)
            {
                //统计每一个顶点的相邻顶点数(连通路口数)
                for (int j = 0; j < nNodeCnt; *pOdd += (aMat[i][j++] != nInf));
                //如果发现奇顶点，加入奇顶点数组
                if (*pOdd % 2 != 0)
                {
                    *(pOdd++) = i;
                }
            }
            //如果存在两个奇顶点，则开始Floyd算法，找最短路径
            if (pOdd != aOdd)
            {
                for (int k = 0, nSum; k < nNodeCnt; ++k)
                {
                    for (int i = 0; i < nNodeCnt; ++i)
                    {
                        //为加快运算减少代码，设置临时变量p = aMat[i]
                        for (int j = 0, *p = &aMat[i][0]; j < nNodeCnt; ++j)
                        {
                            nSum = p[k] + aMat[k][j];
                            p[j] = nSum < p[j] ? nSum : p[j];
                        }
                    }
                }
                nRout += aMat[aOdd[0]][aOdd[1]];
            }
            //输出最小路径长度
            cout << nRout << endl;
            //初始化数据，以便进行下一轮计算
            fill(&aMat[0][0], &aMat[nNodeCnt][0], nInf);
            fill(&aIdHash[0], &aIdHash[26], nInf);
            nRout = nNodeCnt = 0;
            continue;
        }
        //街道名称的首尾字母
        int nF = *strName.begin() - 'a', nL = *(strName.end() - 1) - 'a';
        //验证路口字母是否已经存在，否则添加路口
        nF = (aIdHash[nF] = aIdHash[nF] == nInf ? nNodeCnt++ : aIdHash[nF]);
        nL = (aIdHash[nL] = aIdHash[nL] == nInf ? nNodeCnt++ : aIdHash[nL]);
        //在邻接距阵中添加路口节点
        aMat[nF][nL] = aMat[nL][nF] = strName.length();
        //统计路径长度
        nRout += strName.length();
    }
    return 0;
}