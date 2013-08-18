#include<stdio.h>
#include<string.h>
#include<ctype.h>
char cmd[20], morp[5], roro[5];      //cmd存储输入的指令，morp and roro 截指令
int block[30], point[30][2];        //block数组存储障碍物，
//point[i][0]存储它所在的堆，point[i][1]存储所连接的堆 以数组下标存储


int ifctn(int n, int m)
{
    //判断指令是否无效，返回0表示有效，返回1表示无效
    int t;
    t = n;
    while (point[t][1] != t)
    {
        t = point[t][1];
        if (t == m) return 1;
    }
    t = m;
    while (point[t][1] != t)
    {
        t = point[t][1];
        if (t == n) return 1;
    }
    return 0;
}

int del(int n)
{
    int t, k;
    t = k = n;
    while (point[t][1] != t)
    {
        t = point[t][1];
        point[n][1] = n;
        point[t][0] = t;    //不需要处理point[n][0]
        n = t;
    }
    return 0;
}

int Traver(int n)
{
    int i, t;
    for (i = 0; i < n; ++i)
    {
        printf("%d:", block[i]);

        if (point[i][0] == i)
        {
            printf(" %d", block[i]);
            t = i;
            while (point[t][1] != t)
            {
                t = point[t][1];
                printf(" %d", block[t]);
            }
        }
        printf("\n");
    }
    return 0;
}


int main()
{
    int i, j, T, t, n, flag, len, a, b;
    scanf("%d", &n);
    getchar();
    memset(cmd, '\0', sizeof(char) * 20);
    memset(morp, '\0', sizeof(morp));
    memset(roro, '\0', sizeof(roro));
    for (i = 0; i < 30; ++i)
    {
        block[i] = i;
        point[i][0] = point[i][1] = i;  //查看是否移除时，直接判断point[i][0] 的值是否为本身
    }
    //Traver(n);
    while (fgets(cmd, 20, stdin) != NULL)
    {
        flag = 0;
        len = strlen(cmd);
        if (cmd[len - 1] == '\n') cmd[--len] = '\0';
        if (strcmp(cmd, "quit") == 0) break;
        memcpy(morp, cmd, 4 * sizeof(char));
        a = cmd[5] - '0';
        if (isdigit(cmd[6]))
        {
            a = a * 10 + (cmd[6] - '0');
            flag = 1;
        }
        memcpy(roro, cmd + 7 + flag, 4 * sizeof(char));
        b = cmd[12 + flag] - '0';
        if (isdigit(cmd[12 + flag + 1])) b = b * 10 + (cmd[12 + flag + 1] - '0');
        //    printf("%s %d %s %d\n", morp, a, roro, b);
        if (a == b || ifctn(a, b))continue;
        if (strcmp(morp, "move") == 0)
        {
            if (strcmp(roro, "onto") == 0)
            {
                if (point[a][1] != a) del(a);
                if (point[a][0] != a) point[(point[a][0])][1] = point[a][0];
                if (point[b][1] != b) del(b);
                point[b][1] = a;
                point[a][0] = b;
            }
            else
            {
                t = b;
                while (point[t][1] != t)  t = point[t][1];
                if (point[a][1] != a) del(a);
                if (point[a][0] != a) point[(point[a][0])][1] = point[a][0];
                point[a][0] = t;
                point[t][1] = a;
            }
        }
        else
        {
            if (strcmp(roro, "onto") == 0)
            {
                if (point[b][1] != b) del(b);
                if (point[a][0] != a) point[(point[a][0])][1] = point[a][0];
                point[b][1] = a;
                point[a][0] = b;
            }
            else
            {
                t = b;
                while (point[t][1] != t)  t = point[t][1];
                if (point[a][0] != a) point[(point[a][0])][1] = point[a][0];
                point[t][1] = a;
                point[a][0] = t;
            }
        }

    }
    Traver(n);
    return 0;
}