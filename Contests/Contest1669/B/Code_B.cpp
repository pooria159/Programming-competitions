#include <bits/stdc++.h>
using namespace std;

#define int long long 
// #define endl "\n"
// #define file_io freopen("input.txt","r",stdin);freopen("output.txt","w",stdout)
// #define fastio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)

int32_t main()
{
    // fastio;
    // file_io;
    int t;
    cin >> t;
    while(t--)
    {
        map <int, int> mp;
        int n, ans = -1;
        cin >> n;
        int a[n];
        for(int i = 0; i < n; i++) 
        {
            cin >> a[i];
            mp[a[i]]++;
            if(mp[a[i]] > 2) 
            {
                ans = a[i];
            }
        }
        cout << ans << endl;
    }
}