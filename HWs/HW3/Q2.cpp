#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"
#define file_io freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout)
#define fastio ios::sync_with_stdio(0)cin.tie(0);cout.tie(0)
#define pb push_back
#define PI 3.14159
#define pii pair<int, int>
#define max *max_element
#define min *min_element
map<int, int> mp;


int32_t main()
{
    int n , ans =0;
    cin >> n;
    vector<bool>res(n+1,true);
    res[0] =false;res[1] = false;
    if(n==2)ans++;
    for(int i = 2 ; i < n; i++){
        if (res[i]==true){ 
            ans++;
            for(int j=2*i ; j < n ; j= j +i)res[j]=0;
        }
    }
    cout << ans << endl;
}
