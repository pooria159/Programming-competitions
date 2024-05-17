#include <bits/stdc++.h>
using namespace std;

#define int long long 
#define endl "\n"
#define file_io freopen("input.txt","r",stdin);freopen("output.txt","w",stdout)
#define fastio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define pb push_back
#define PI 3.14159
#define pii pair<int,int>
#define max INT32_MAX
map<int, int> mp;

int32_t main()
{
    fastio;
    int t;
    cin >> t;
    while (t--)
    {
        int n , k = 0 , ans = 0 , x = 0;
        cin >> n;
        int a[n];
        for (int i = 0; i < n ; i++) 
        {cin >> a[i];}
        for (int j = 0 ; j < n ; j++)
        { 
            if(a[j] == 0 && a[0]!=0)
            {   
                x++;
                sort(a , a+k+1);
                ans+=a[j-x];
                for(int i = 0; i < k ; i++)
                {
                    a[k] = 0;
                }
            }
            else{
                k++;
            }
        }
        cout << ans << endl;
        
        
    }
}