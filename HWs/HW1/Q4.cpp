#include <bits/stdc++.h>
using namespace std;

#define int long long 
#define endl "\n"
// #define file_io freopen("input.txt","r",stdin);freopen("output.txt","w",stdout)
#define fastio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define pb push_back


int32_t main()
{
    int a , res = 0;
    cin >> a;
    vector<int> v;
    while(a){
      v.pb(a%2);
      res += a%2;
      a /= 2;
    }
    cout << res << endl;
    for(int j = 0; j < v.size(); j++){
        if(v[j] == 1){
            cout << j << " ";
        }
    }
}