#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

const int MAXN = 10000;
char inStr[MAXN];
char expStr[MAXN];
int num[MAXN];
int pos , cnt , sum;

void init(char *str)
{
    int len = strlen(str);
    bool isLeft = true;
    pos = sum = 0;
    cnt = 1;
    int i = 0;
    while (i < len)
    {
        if (isalnum(str[i]))
        {
            int j = i;
            int tmp = 0;
            while (j < len && isalnum(str[j]))
            {
                tmp = tmp * 10 + str[j] - '0';
                j++;
            }
            sum += tmp;
            num[pos++] = tmp;
            i = j - 1;
        }
        else
        {
            if (str[i] != ' ')
                expStr[pos] = str[i];
            if (str[i] == '+' && isLeft)
                cnt++;
            if (str[i] == '=')
                isLeft = false;
            if (str[i] == '-' && !isLeft)
                cnt++;
        }
        i++;
    }
}

void output(int *arr , int tmpPos)
{
    bool vis[MAXN];
    bool isLeft = true;
    memset(vis , false , sizeof(vis));
    for (int i = 0 ; i <= tmpPos ; i++)
        vis[arr[i]] = true;
    int tmpArr[MAXN];
    int tmpArrPos = 0;
    for (int i = 0 ; i < pos ; i++)
        if (!vis[i])
            tmpArr[tmpArrPos++] = i;
    tmpArrPos--;

    printf("%d" , num[arr[tmpPos--]]);
    for (int i = 1 ; i < pos ; i++)
    {
        if (expStr[i] == '+')
        {
            if (isLeft)
                printf(" + %d" , num[arr[tmpPos--]]);
            else
                printf(" + %d" , num[tmpArr[tmpArrPos--]]);
        }
        else if (expStr[i] == '-')
        {
            if (!isLeft)
                printf(" - %d" , num[arr[tmpPos--]]);
            else
                printf(" - %d" , num[tmpArr[tmpArrPos--]]);
        }
        else
        {
            isLeft = false;
            printf(" = %d" , num[tmpArr[tmpArrPos--]]);
        }
    }
    printf("\n");
}

void solve()
{
    int tmpNum = (1 << pos) - 1;
    int arr[MAXN];
    sum >>= 1;
    while (tmpNum)
    {
        int tmp = tmpNum;
        int tmpCnt = -1;
        int tmpPos = pos - 1;
        int tmpSum = 0;
        while (tmp)
        {
            if (tmp & 1)
            {
                tmpCnt++;
                arr[tmpCnt] = tmpPos;
                tmpSum += num[tmpPos];
            }
            tmpPos--;
            tmp >>= 1;
            if (tmpSum > sum || tmpCnt + 1 > cnt)
                break;
        }
        if (tmpCnt + 1 == cnt && tmpSum == sum)
        {
            output(arr , tmpCnt);
            return;
        }
        tmpNum--;
    }
    printf("no solution\n");
}

int main()
{
    while (gets(inStr))
    {
        init(inStr);
        if (sum & 1) //如果是奇数
            printf("no solution\n");
        else
            solve();
    }
    return 0;
}

