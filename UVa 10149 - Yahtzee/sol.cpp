//
//  UVa 10149 Yahtzee
//  time: 0.015s
//  rank: 33
//  Created by 杨峻 on 13-6-5.
//  Copyright (c) 2013年 www.51dx.net. All rights reserved.
//

#include <stdio.h>
#include <algorithm>
#include <queue>
#include <string.h>
using namespace std;

#define NUMROUND    13
#define NUMCATEGORY 13

class mycmp
{
private:
    int m_category;
    int (*m_pscore)[NUMROUND + 1];
public:
    mycmp(int category, int (*pscore)[NUMROUND + 1])
        : m_category(category)
        , m_pscore(pscore)
    {
    }
    bool operator() (int i, int j)
    {
        return m_pscore[i][m_category] >= m_pscore[j][m_category];
    }
};

struct SN
{
    int category[NUMCATEGORY + 1];  //catgory => round
    int rnd2cat[NUMROUND + 1]; //round => category
    int score;
    //int bonus;
    int s6;
};

struct TRACK
{
    SN sn;
    int conf_cat;
    int round;
    int diff;
    int except;
};

class Yahtzee
{
private:
    int m_dices[NUMROUND + 1][7];
    int m_sortedrnd[NUMCATEGORY + 1][NUMROUND + 1];
    SN m_sn[NUMCATEGORY + 1];
    int m_rndxcat[NUMROUND + 1][NUMCATEGORY + 1];

public:
    bool input()
    {
        memset(this, 0, sizeof(*this));
        char buff[130];
        fread(buff, 1, sizeof(buff), stdin);
        if (feof(stdin))
        {
            return false;
        }
        char *p = buff;
        for (int i = 1; i <= NUMROUND; ++i)
        {
            for (int j = 1; j <= 5; ++p)
            {
                if (*p <= 32)
                {
                    continue;
                }
                ++m_dices[i][*p - '0'];
                ++j;
            }
        }
        return true;
    }

    void output()
    {
        for (int i = 1; i <= NUMCATEGORY; ++i)
        {
            int round = m_sn[NUMCATEGORY].category[i];
            //printf("%d ", m_rndxcat[round][i]);
            printf("%d ", m_rndxcat[round][i]);
        }
        int bonus = m_sn[NUMCATEGORY].s6 >= 63 ? 35 : 0;
        printf("%d %dn", bonus, m_sn[NUMCATEGORY].score);
    }

    void cal()
    {
        initdata();
        queue<TRACK> q;
        for (int i = 1; i <= NUMCATEGORY; ++i)
        {
            const SN &subsn = m_sn[i - 1];
            m_sn[i] = subsn;
            SN &sn = m_sn[i];

            for (int j = 0; int r = m_sortedrnd[i][j]; ++j)
            {
                if (!subsn.rnd2cat[r])
                {
                    if (i > 6)
                    {
                        sn.score += m_rndxcat[r][i];
                        sn.category[i] = r;
                        sn.rnd2cat[r] = i;
                    }
                    else
                    {
                        sn.category[i] = r;
                        sn.rnd2cat[r] = i;
                        int oldscore = sn.score;
                        sn.score += m_rndxcat[r][i];
                        if (oldscore < 63 && sn.score >= 63)
                        {
                            sn.score += 35;
                        }
                        sn.s6 = sn.score;
                    }
                    break;
                }
                TRACK item = { subsn, subsn.rnd2cat[r], r, m_rndxcat[r][i], 1 << r };
                item.sn.rnd2cat[r] = i;
                item.sn.category[i] = r;
                if (i <= 6)
                {
                    int olds6 = item.sn.s6;
                    item.sn.s6 += m_rndxcat[r][i];
                    if (olds6 < 63 && item.sn.s6 >= 63)
                    {
                        item.sn.s6 += 35;
                        item.diff += 35;
                    }
                }
                q.push(item);
            }

            while (!q.empty())
            {
                int minvalue = sn.score - subsn.score;
                TRACK &item = q.front();
                SN &tracksn = item.sn;
                int round = item.round;
                int conf_cat = item.conf_cat;
                for (int j = 0; int r = m_sortedrnd[conf_cat][j]; ++j)
                {
                    if (1 << r & item.except)
                    {
                        continue;
                    }
                    int diff = m_rndxcat[r][conf_cat] - m_rndxcat[round][conf_cat];
                    int s6 = tracksn.s6;
                    if (conf_cat <= 6)
                    {
                        s6 += diff;
                        if (tracksn.s6 >= 63 && s6 < 98)
                        {
                            s6 -= 35;
                            diff -= 35;
                        }
                    }

                    diff += item.diff;
                    if (diff <= minvalue)
                    {
                        break;
                    }
                    if (!(tracksn.rnd2cat[r]))
                    {
                        tracksn.score += diff;
                        if (tracksn.score > sn.score)
                        {
                            sn = tracksn;
                            sn.s6 = s6;
                            sn.category[conf_cat] = r;
                            sn.rnd2cat[r] = conf_cat;
                        }
                        break;
                    }
                    q.push(item);
                    TRACK &tmp = q.back();
                    tmp.conf_cat = tracksn.rnd2cat[r];
                    tmp.sn.category[conf_cat] = r;
                    tmp.sn.rnd2cat[r] = conf_cat;
                    tmp.sn.s6 = s6;
                    tmp.round = r;
                    tmp.except |= 1 << r;
                    tmp.diff = diff;
                }
                q.pop();
            }
        }
    }

    void initdata()
    {
        for (int i = 1; i <= NUMCATEGORY; ++i)
        {
            for (int j = 1; j <= NUMROUND; ++j)
            {
                m_rndxcat[j][i] = _getscore(j, i);
            }
        }

        for (int i = 1; i <= NUMCATEGORY; ++i)
        {
            for (int j = 0; j <= NUMROUND; ++j)
            {
                m_sortedrnd[i][j] = j;
            }
            mycmp cmp(i, &m_rndxcat[0]);
            sort(&m_sortedrnd[i][0], m_sortedrnd[i] + NUMROUND + 1, cmp);
        }
    }

    int sumdice(int dice[])
    {
        int sum = 0;
        for (int i = 1; i <= 6; ++i)
        {
            sum += dice[i] * i;
        }
        return sum;
    }

    int _getscore(int round, int category)
    {
        if (category >= 1 && category <= 6)  //前六项计分项
        {
            return m_dices[round][category] * category;
        }
        if (category == 7)   //机会
        {
            return sumdice(m_dices[round]);
        }
        if (category == 8)   //三同
        {
            for (int i = 1; i <= 6; ++i)
            {
                if (m_dices[round][i] >= 3)
                {
                    return sumdice(m_dices[round]);
                }
            }
            return 0;
        }
        if (category == 9)   //四同
        {
            for (int i = 1; i <= 6; ++i)
            {
                if (m_dices[round][i] >= 4 )
                {
                    return sumdice(m_dices[round]);
                }
            }
            return 0;
        }
        if (category == 10)   //五同
        {
            for (int i = 1; i <= 6; ++i)
            {
                if (m_dices[round][i] >= 5)
                {
                    return 50;
                }
            }
            return 0;
        }
        if (category == 11)   //小顺
        {
            for (int i = 1; i <= 3; ++i)
            {
                if (m_dices[round][i]
                        && m_dices[round][i + 1]
                        && m_dices[round][i + 2]
                        && m_dices[round][i + 3])
                {
                    return 25;
                }
            }
            return 0;
        }
        if (category == 12)   //大顺
        {
            for (int i = 1; i <= 2; ++i)
            {
                if (m_dices[round][i]
                        && m_dices[round][i + 1]
                        && m_dices[round][i + 2]
                        && m_dices[round][i + 3]
                        && m_dices[round][i + 4])
                {
                    return 35;
                }
            }
            return 0;
        }
        if (category == 13)   //葫芦
        {
            bool bthree = false;
            bool btwo = false;
            for (int i = 1; i <= 6; ++i)
            {
                if (m_dices[round][i] == 3)
                {
                    bthree  = true;
                }
                if (m_dices[round][i] == 2)
                {
                    btwo    = true;
                }
            }
            if (bthree && btwo)
            {
                return 40;
            }
        }
        return 0;
    }
};
int main(int argc, const char *argv[])
{
    Yahtzee y;
    while (y.input())
    {
        y.cal();
        y.output();
    }
    return 0;
}