#include <bits/stdc++.h>
using namespace std;

#define int long long 
#define endl "\n"
// #define file_io freopen("input.txt","r",stdin);freopen("output.txt","w",stdout)
#define fastio ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr)

int32_t main()
{
    fastio;
    int t , ans=0;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        int n , k;
        cin >> n >> k;
        for (int j = 0; j <  n ; j++)
        {
            int a , b;
            cin >> a >> b;
            for(int h=a ; h <= b ; h++)
            {
                if(h==k)
                {
                    ans++;
                }
            }
        }
        if(ans==0)
        {
            cout << "NO" << endl;
            ans = 0;
        }
        else if(ans >= 1 && n == ans)
        {
            cout << "NO" << endl;
            ans = 0;
        }
        else if(ans >= 1 && n > ans)
        {
            cout << "YES" << endl;
            ans = 0;
        }
    }
}