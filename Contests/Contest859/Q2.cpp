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
    while(t--)
    {
        int n , even = 0 , odd = 0;
        cin >> n;
        int a[n];
        for (int i = 0; i < n ; i++)
        {
            cin >> a[i];
            if(a[i]%2==0)
            {
                even+=a[i];
            }
            else if(a[i]%2!=0)
            {
                odd+=a[i];
            }
        }
        (even > odd) ? cout << "Yes" << endl : cout << "No" << endl;
    }
}