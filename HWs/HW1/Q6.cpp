#include <bits/stdc++.h>
using namespace std;

#define int long long 
#define endl "\n"
// #define file_io freopen("input.txt","r",stdin);freopen("output.txt","w",stdout)
#define fastio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)

int32_t main()
{
    int n , a = 1 , b=2;
    cin >> n;
    string str[200];
    for (int i = 0; i < 200 ; i++){
        str[i] = "-";
    }
    while (a < 100)
    {
        str[a]="+";
        str[b] = "+";
        a= a+b;
        b= a+b;
    }
    for (int h = 1; h <=  n; h++)
    {
        cout << str[h];
    }
    
}