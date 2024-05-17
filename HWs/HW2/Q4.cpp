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
        int n , ans = 0;
        cin >> n;
        int mark[10] = {0};
        mp.clear();
        for (int i = 0; i < n; i++){
            int a;
            cin >> a;
            if(a > 9){
                mark[to_string(a).length()]++;
                mp[a]++; ans++;
            }
            else
                mark[a]++ ;
        }
        for (int j = 0; j < n; j++){
            int a;
            cin >> a;
            if(mp[a]){
                mark[to_string(a).length()]--;
                mp[a]--; ans--;
            }
            if(a > 9){
                mark[to_string(a).length()]--;
                ans++;
            }
            else
                mark[a]--;

        }
        for (int i = 2; i <= 9; i++){
            mark[i] < 0 ? ans-=mark[i] : ans+=mark[i];
        }
        cout << ans << endl;
    }
}



