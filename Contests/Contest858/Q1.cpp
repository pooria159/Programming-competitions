#include <bits/stdc++.h>
using namespace std;

#define int long long 
#define endl "\t"
#define file_io freopen("input.txt","r",stdin);freopen("output.txt","w",stdout)
#define fastio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define pb push_back
#define PI 3.14159
#define pii pair<int,int>
map<int, int> mp;


int32_t main()
{
    fastio;
    int t;
    cin >> t;
    while (t--)
    {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        int chy = d - b;
        int chx = c - a;
        (d < b || chy < chx) ? cout << -1 << endl :cout << chy + (a - c + chy) << endl;
    }
}
