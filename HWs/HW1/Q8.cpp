#include <bits/stdc++.h>
using namespace std;

#define int long long 
#define endl "\n"
// #define file_io freopen("input.txt","r",stdin);freopen("output.txt","w",stdout)
#define fastio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)

int32_t main()
{
    int n = 0 , m = 0;
    string line;
    cin >> line;
    for(int i = 0; i < line.length(); i++)
    {
        line[i] == '0' ? n++ : m++;
    }
    cout << 2*min(n,m) << endl;
}