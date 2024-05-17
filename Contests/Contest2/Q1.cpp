#include <bits/stdc++.h>
using namespace std;

#define int long long 
#define endl "\n"
// #define file_io freopen("input.txt","r",stdin);freopen("output.txt","w",stdout)
#define fastio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define pb push_back
#define PI 3.14159
#define pii pair<int,int>
#define max INT32_MAX

int32_t main()
{
    fastio;
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        int a[n];
        for(int i=0; i<n; i++)
        {
            cin >> a[i];
        }
        int mn = 1e9 + 100;
        for(int i= 0 ; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                mn = min(mn, __gcd(a[i], a[j]));
            }
        }
        if (mn > 2)
            cout << "No" << endl;
        else
            cout << "Yes" << endl;
    }
}