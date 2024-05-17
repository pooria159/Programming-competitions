#include <bits/stdc++.h>
#include <bitset>
using namespace std;

#define int long long 
#define endl "\n"
// #define file_io freopen("input.txt","r",stdin);freopen("output.txt","w",stdout)
#define fastio ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr)
#define pb push_back

int32_t main(){
    fastio;
    // file_io;
    int t;
    cin >> t;

    while(t--){
      int n , m , ans = 0;
      cin >> n >> m;
      int a[n];
      int b[32] = {0};
      vector<int> v[n];
      for (int i = 0; i < n ; i++){
        cin >> a[i];
        while (a[i]){
          v[i].pb(a[i]%2);
          a[i] /= 2;
        }
        for(int j = 0; j < v[i].size(); j++){
          b[j] += v[i][j];
        }
      }
      for ( int i = 30 ; i > -1; i--)
      {
        int x = n - b[i];
        if ( x <= m)
        {
          m -= x;
          ans += pow(2,i);
        }
      }
      cout << ans << endl;
    }
}


