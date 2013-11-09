#include <iostream>
#include <iomanip>
using namespace std ;
#include <algorithm>
#include <cstring>
#define MaxN 52
void post_order( char *preOrder, char *inOrder, int N, char *postOrder )
{
    char *root ;
    int numLeft = 0 ;
    int numRight = 0 ;
    root = strchr( inOrder, preOrder[ 0 ] ) ;
    numLeft = root - inOrder ;
    numRight = N - 1 - numLeft ;
    postOrder[ N - 1 ] = *root ;
    if ( numLeft > 0 )
    {
        post_order( preOrder + 1, inOrder, numLeft, postOrder ) ;
    }
    if ( numRight > 0 )
    {
        post_order( preOrder + 1 + numLeft, inOrder + numLeft + 1, N - numLeft - 1,
                    postOrder + numLeft ) ;
    }
}
int main()
{
    int C = 0 ;
    int N = 0 ;
    char preOrder[ MaxN + 1 ] = { 0 } ;
    char inOrder[ MaxN + 1 ] = { 0 } ;
    char postOrder[ MaxN + 1 ] = { 0 } ;
    int i = 0 ;
    int j = 0 ;
    cin >> C ;
    for ( i = 1 ; i <= C ; i++ )
    {
        cin >> N >> preOrder >> inOrder ;
        post_order( preOrder, inOrder, N, postOrder ) ;
        postOrder[ N ] = '\0' ;
        cout << postOrder << endl ;
    }
    return 0 ;
}