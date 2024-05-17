#include <bits/stdc++.h>
using namespace std;

#define int long long 
#define endl "\n"
// #define file_io freopen("input.txt","r",stdin);freopen("output.txt","w",stdout)
#define fastio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)

int32_t main()
{
    int n , m , res = 0;
    cin >> n >> m;
    for (int i = 0; i < n ; i++)
    {
        int a;
        cin >> a;
        res += a;
    }
    (res >= m) ? cout <<"YES" : cout <<"NO";
}