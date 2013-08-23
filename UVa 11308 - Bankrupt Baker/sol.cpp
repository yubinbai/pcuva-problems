#include <iostream>
#include <string>
#include <map>
#include <algorithm>
#include <cctype>
#include <vector>
#include <utility>

using namespace std;

map< string, int > ingredientCost;

vector< pair< int, string > > ans;

int main()
{
    int test;
    string title;
    int M, N, B;
    string ingredient;
    int cost;
    string recipe;
    int k;
    string requirement;
    int x;

    cin >> test;
    cin.ignore();
    while ( test-- )
    {
        getline( cin, title );
        for (int i = 0; i < title.length(); i++) title[ i ] = toupper( title[ i ] );
        cout << title << endl;

        cin >> M >> N >> B;
        cin.ignore();
        ingredientCost.clear();
        for (int i = 0; i < M; i++)
        {
            cin >> ingredient >> cost;
            cin.ignore();
            ingredientCost[ ingredient ] = cost;
        }
        ans.clear();
        for (int i = 0; i < N; i++)
        {
            getline( cin, recipe );
            cin >> k;
            cost = 0;
            for (int j = 0; j < k; j++)
            {
                cin >> requirement >> x;
                cin.ignore();
                cost += ingredientCost[ requirement ] * x;
            }
            if ( cost <= B ) ans.push_back( make_pair( cost, recipe ) );
        }
        if ( ans.size() == 0 ) cout << "Too expensive!" << endl;
        else
        {
            sort( ans.begin(), ans.end() );
            for (int i = 0; i < ans.size(); i++)
            {
                cout << ans[i].second << endl;
            }
        }
        cout << endl;
    }

    return 0;
}
