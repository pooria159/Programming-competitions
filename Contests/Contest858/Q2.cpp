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
        int n;
        cin >> n;
        vector<int> v(n);
        for (int i = 0; i < n; i++)cin >> v[i];
        int start = v[0] ,end = v[0];
        int mx = 1 ,mi = 1;
        for (int i = 1; i < n; i++)
        {
            if (v[i] > end){end = v[i];mx = 1;} 
            else if (v[i] == end)mx++;
            if (v[i] < start) {start = v[i];mi = 1;} 
            else if (v[i] == start)mi++;
        }
        if(start > 0){cout << 0 << endl;}
        else if(mi <= ((n+1) / 2) && end > 0){cout << 0 << endl;} 
        else{(end != 1) ? cout << 1 << endl :cout << 2 << endl;}
    }
}
