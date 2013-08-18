#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
const int maxn = 10010;
//-----------------------------
class arr
{
public:
    string name;
    int address;
    int size;
    int D;
    int u[21], l[21];
};

//-----------------------------
arr list[maxn];
int n, r;
//-----------------------------
void calculate(string Name)      //Calculate the physical address
{
    int index, result = 0;
    int value[20], c[20];
    for (int i = 1; i <= n; i++) //Find the name index in list[]
        if (list[i].name == Name)
        {
            index = i;
            break;
        }
    c[list[index].D] = list[index].size;  //Cd
    //Initial for Co
    c[0] = list[index].address - c[list[index].D] * list[index].l[list[index].D];
    //Read the value
    for (int i = 1; i <= list[index].D; i++) cin >> value[i];
    //Calculate Ci and update Co
    for (int i = list[index].D - 1; i >= 1; i--)
    {
        c[i] = c[i + 1] * (list[index].u[i + 1] - list[index].l[i + 1] + 1);
        c[0] -= c[i] * list[index].l[i];
    }
    result = c[0];
    //Calculate the result
    for (int i = 1; i <= list[index].D; i++)
        result += c[i] * value[i];
    //Print output
    cout << Name << "[";
    for (int i = 1; i <= list[index].D - 1; i++) cout << value[i] << ", ";
    cout << value[list[index].D];
    printf("] = %d\n", result);
}
//-----------------------------
void readfile()
{
    string Name = "";
    cin >> n >> r;
    getline(cin, Name);
    for (int i = 1; i <= n; i++)
    {
        char c;
        Name = "";
        scanf("%c", &c);
        while (c != ' ')              //Read the name
        {
            Name = Name + c;
            scanf("%c", &c);
        }
        list[i].name = Name;        //Store in list
        //Read others
        scanf("%d%d%d", &list[i].address, &list[i].size, &list[i].D);
        for (int j = 1; j <= list[i].D; j++) cin >> list[i].l[j] >> list[i].u[j];
        getline(cin, Name);           //Go to new line to read
    }
    for (int i = 1; i <= r; i++)
    {
        char c;
        Name = "";
        scanf("%c", &c);
        while (c != ' ')              //Read the name
        {
            Name = Name + c;
            scanf("%c", &c);
        }
        calculate(Name);            //Calculate the name
        getline(cin, Name);           //Go to new line to read
    }
}
//-----------------------------
int main()
{
    readfile();
    return 0;
}
//-----------------------------