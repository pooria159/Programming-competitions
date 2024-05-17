#include <bits/stdc++.h>
using namespace std;

#define int long long 
#define endl "\n"
// #define file_io freopen("input.txt","r",stdin);freopen("output.txt","w",stdout)
#define fastio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define pb push_back
#define pii pair<int,int>


int32_t main()
{
    fastio;
    int t;
    cin >> t;
    while(t--)
    {
        int n , ans = 0;
        cin >> n;
        string str;
        cin >> str;
        int a[n+1] ,  b[n+1];
        set <char> first, second;
        for(int i = 0; i < n ; i++)
        {
            first.insert(str[i]);
            a[i] = first.size();
        }
        for (int j = n - 1; j > -1 ; j--)
        {
            second.insert(str[j]);
            b[j] = second.size();
        }
        for (int h = 0; h < n - 1; h++)
        {
            if(a[h]+b[h+1]>ans){
                ans = a[h]+b[h+1];
            }
        }
        cout << ans << endl;
    }
}