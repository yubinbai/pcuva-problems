#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
char poke[12][4], temp[12][4];
int transfer[6][2];
char output[10][20];
int res;

void memset_1(char (*des)[4], char (*src)[4])
{
    for (int i = 0; i < 10; i++)
        strcpy(des[i], src[i]);
    return;
}

int  prior(char elem)
{
    if ('2' <= elem && elem <= '9') return (elem - '0');
    switch (elem)
    {
    case 'A' : return 1;
    case 'T' : return 10;
    case 'J' : return 11;
    case 'Q' : return 12;
    case 'K' : return 13;

    case 'C' : return 1;
    case 'D' : return 2;
    case 'H' : return 3;
    case 'S' : return 4;
    }
    return -1;
}

void swap_1(int left, int right)
{
    int sw[2];
    sw[0] = transfer[left][0];
    sw[1] = transfer[left][1];
    transfer[left][0] = transfer[right][0];
    transfer[left][1] = transfer[right][1];
    transfer[right][0] = sw[0];
    transfer[right][1] = sw[1];
    return;
}

void basesort()
{
    for (int i = 0; i < 5; ++i)
    {
        for (int j = 0; j <= 1; ++j)
            transfer[i][j] = prior(temp[i][j]);
    }
    for (int i = 0; i < 4; ++i)
    {
        int flag = 0;
        for (int j = 0; j < 4 - i; ++j)
            if (transfer[j][0] > transfer[j + 1][0])
            {
                swap_1(j, j + 1);
                flag = 1;
            }
        if (!flag) break;
    }
    for (int part1 = 0, part2 = 0, i = 0; i < 5; i++)
    {
        if (i + 1 < 5 && transfer[i][0] == transfer[i + 1][0])
            part2++;
        else
        {
            for (int t = 0; t < part2 - part1; ++t)
            {
                int flag = 0;
                for (int j = part1; j < part2 - t; ++j)
                    if (transfer[j][1] > transfer[j + 1][1])
                    {
                        swap_1(j, j + 1);
                        flag = 1;
                    }
                if (!flag) break;
            }
            part1 = part2 = i + 1;
        }
    }
    return;
}

void Print()
{
    for (int i = 0; i < 5; ++i)
        cout << temp[i] << " ";
    return;
}

int is_straight_flush()
{
    int flag = 1;
    for (int i = 1; i < 5; ++i)
    {
        if (transfer[i - 1][0] + 1 != transfer[i][0] || transfer[i - 1][1] != transfer[i][1])
        {
            flag = 0;
            break;
        }
    }
    if (flag) return 1;
    else
    {
        if (transfer[0][0] == 1 && transfer[1][0] == 10 && transfer[0][1] == transfer[1][1])
        {
            flag = 1;
            for (int i = 2; i < 5; ++i)
                if (transfer[i - 1][0] + 1 != transfer[i][0] || transfer[i - 1][1] != transfer[i][1])
                {
                    flag = 0;
                    break;
                }
        }
        return flag;
    }
}

int is_four()
{
    for (int i = 0; i <= 1; ++i)
    {
        int flag = 1;
        for (int j = i + 1; j < 4 + i; ++j)
        {
            if (transfer[j][0] != transfer[j - 1][0])
            {
                flag = 0;
                break;
            }
        }
        if (flag) return 1;
    }
    return 0;

}

int is_full()
{
    if (transfer[0][0] == transfer[1][0] && transfer[3][0] == transfer[4][0])
    {
        if (transfer[1][0] == transfer[2][0] || transfer[2][0] == transfer[3][0])
            return 1;
    }
    return 0;
}

int is_flush()
{
    for (int i = 1; i < 5; ++i)
        if (transfer[i - 1][1] != transfer[i][1])
            return 0;
    return 1;
}

int is_straight()
{
    int flag = 1;
    for (int i = 1; i < 5; ++i)
        if (transfer[i - 1][0] + 1 != transfer[i][0])
        {
            flag = 0;
            break;
        }
    if (flag) return 1;
    else
    {
        if (transfer[0][0] == 1 && transfer[1][0] == 10)
        {
            flag = 1;
            for (int i = 2; i < 5; ++i)
                if (transfer[i - 1][0] != transfer[i][0])
                {
                    flag = 0;
                    break;
                }
        }
        return flag;
    }
}

int is_three()
{
    for (int i = 0; i <= 2; ++i)
    {
        if (transfer[i][0] == transfer[i + 1][0] && transfer[i + 1][0] == transfer[i + 2][0])
            return 1;
    }
    return 0;
}

int is_two()
{
    if (transfer[0][0] == transfer[1][0])
    {
        if (transfer[2][0] == transfer[3][0] || transfer[3][0] == transfer[4][0])
            return 1;
    }
    if (transfer[1][0] == transfer[2][0] && transfer[3][0] == transfer[4][0])
        return 1;
    return 0;
}

int is_one()
{
    for (int i = 0; i <= 3; ++i)
    {
        if (transfer[i][0] == transfer[i + 1][0]) return 1;
    }
    return 0;
}

void Traverse()
{
    basesort();

    if (is_straight_flush())
    {
        res = 0;
        return;
    }
    if (is_four())
    {
        res = 1;
        return;
    }
    if (is_full())
    {
        res = res < 2 ? res : 2;
        return;
    }
    if (is_flush())
    {
        res = res < 3 ? res : 3;
        return;
    }
    if (is_straight())
    {
        res = res < 4 ? res : 4;
        return;
    }
    if (is_three())
    {
        res = res < 5 ? res : 5;
        return;
    }
    if (is_two())
    {
        res = res < 6 ? res : 6;
        return;
    }
    if (is_one())
    {
        res = res < 7 ? res : 7;
        return;
    }
}

void memset_2()
{
    strcpy(output[0], "straight-flush");
    strcpy(output[1], "four-of-a-kind");
    strcpy(output[2], "full-house");
    strcpy(output[3], "flush");
    strcpy(output[4], "straight");
    strcpy(output[5], "three-of-a-kind");
    strcpy(output[6], "two-pairs");
    strcpy(output[7], "one-pair");
    strcpy(output[8], "highest-card");
}

int main()
{
    /*  freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    */
    int sequence[6];
    for (int r = 0; r < 6; r++) sequence[r] = r + 1;
    memset_2();
    while (cin >> poke[0])
    {
        for (int i = 2; i <= 10; ++i)
            cin >> poke[i - 1];
        res = 8;
        for (int i = 0; i < (1 << 5); ++i)
        {
            int num = 0;
            memset_1(temp, poke);
            for (int j = 0; j < 5; ++j)
                if (i & (1 << j)) num++;
            sort(sequence, sequence + 6);
            int cnt = 0;
            for (int j = 0; j < 5; ++j)
                if (i & (1 << j)) strcpy(temp[j], temp[(sequence[cnt++] + 4)]);
            Traverse();
            if (res == 0) break;
        }
        cout << "Hand: ";
        for (int i = 0; i < 5; ++i)
            cout << poke[i] << " ";
        cout << "Deck: ";
        for (int i = 5; i < 10; ++i)
            cout << poke[i] << " ";
        cout << "Best hand: ";
        cout << output[res] << endl;
    }
    return 0;
}