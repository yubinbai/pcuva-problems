#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <cctype>
#include <stack>
#include <queue>
#include <list>
#include <vector>
#include <map>
#include <sstream>
#include <cmath>
#include <bitset>
#include <utility>
#include <set>
#include <numeric>
#define INT_MAX 2147483647
#define INT_MIN -2147483648
#define pi acos(-1.0)
#define long long LL
using namespace std;
map< pair<int, int>, vector<int> > CategorizationMemo;
int digitScore(int Dices[5], int Digit)
{
    int Total = 0;
    for (int i = 0; i < 5; i++)
        if (Dices[i] == Digit) Total += Digit;
    return Total;
}
int chance(int Dices[5])
{
    int Total = 0;
    for (int i = 0; i < 5; i++) Total += Dices[i];
    return Total;
}
int ofAKind(int Dices[5], int n, int DicesCount[7])
{
    bool Found = false;
    for (int i = 1; i < 7; i++) if (DicesCount[i] >= n)
        {
            Found = true;
            break;
        }
    if (n == 5 && Found) return 50;
    if (Found) return chance(Dices);
    return 0;
}
int fullHouse(int DicesCount[7])
{
    bool TwoEqual = false, ThreeEqual = false, FiveEqual = false;
    for (int i = 1; i < 7; i++)
        if (DicesCount[i] == 2) TwoEqual = true;
        else if (DicesCount[i] == 3) ThreeEqual = true;
        else if (DicesCount[i] == 5) FiveEqual = true;
    if ((TwoEqual && ThreeEqual) || FiveEqual) return 40;
    else return 0;
}
vector<int> BestCategorization(int RoundsLeft, int Category, int Scores[13][13])
{
    pair<int, int> key;
    vector<int>  HighestScore, TestScore;
    key.first = RoundsLeft;
    key.second = Category;
    map< pair<int, int>, vector<int> >::iterator
    it = CategorizationMemo.find(key);
    if (it != CategorizationMemo.end())
        return it->second;
    HighestScore.resize(15);
    TestScore.resize(15);
    HighestScore[14] = -1;
    if (Category == 0)
    {
        HighestScore[0] = Scores[(int)(log((double)RoundsLeft) / log(2.0))][0];
        HighestScore[14] = HighestScore[0];
        return HighestScore;
    }
    for (int i = 0; i < 13; i++)
    {
        if (RoundsLeft  & (int)pow(2.0, i))
            RoundsLeft ^= (int)pow(2.0, i);
        else continue;
        TestScore = BestCategorization(RoundsLeft, Category - 1, Scores);
        TestScore[14] += Scores[i][Category];
        TestScore[Category] = Scores[i][Category];
        if (Category == 5)
        {
            TestScore[13] = (TestScore[14] >= 63) ? 35 : 0;
            TestScore[14] += TestScore[13];
        }
        if (TestScore[14] > HighestScore[14] ) HighestScore = TestScore;
        RoundsLeft ^= (int)pow(2.0, i);
    }
    CategorizationMemo[key] = HighestScore;
    return HighestScore;
}
int straight(int DicesCount[7], int n)
{
    int LongestSequence = 0, CurrentSequence = 0;
    for (int i = 1; i < 7; i++)
        if (DicesCount[i] && DicesCount[i + 1])
            CurrentSequence++;
        else LongestSequence = max(CurrentSequence + 1, LongestSequence), CurrentSequence = 0;
    if (LongestSequence == n && n == 5) return 35;
    if (LongestSequence >= n && n == 4) return 25;
    return 0;
}
int main ()
{
    int Dices[13][5];
    int Scores[13][13];
    int counter = 0;
    while (1)
    {
        counter++;
        for (int i = 0; i < 13; i++)
            for (int j = 0; j < 13; j++)
                Scores[i][i] = -1;
        int DicesCount[13][7] = {0};
        int Score[14];
        for (int i = 0; i < 13; i++)
        {
            for (int j = 0; j < 5; j++)
                if (scanf("%d", &Dices[i][j]) != 1)return 0;
                else DicesCount[i][Dices[i][j]]++;
            Scores[i][0] = digitScore(Dices[i], 1);
            Scores[i][1] = digitScore(Dices[i], 2);
            Scores[i][2] = digitScore(Dices[i], 3);
            Scores[i][3] = digitScore(Dices[i], 4);
            Scores[i][4] = digitScore(Dices[i], 5);
            Scores[i][5] = digitScore(Dices[i], 6);
            Scores[i][6] = chance(Dices[i]);
            Scores[i][7] = ofAKind(Dices[i], 3, DicesCount[i]);
            Scores[i][8] = ofAKind(Dices[i], 4, DicesCount[i]);
            Scores[i][9] = ofAKind(Dices[i], 5, DicesCount[i]);
            Scores[i][10] = straight(DicesCount[i], 4);
            Scores[i][11] = straight(DicesCount[i], 5);
            Scores[i][12] = fullHouse(DicesCount[i]);
        }
        vector<int> output = BestCategorization(pow(2.0, 13) - 1, 12 , Scores);
        for (int i = 0; i < 15; i++)
        {
            printf("%d", output[i]);
            if (i != 14) printf(" ");
        }
        printf("\n");
        CategorizationMemo.clear();
    }
    return 0;
}