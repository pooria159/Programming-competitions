#include <bits/stdc++.h>
using namespace std;

#define int long long 
#define endl "\n"
// #define file_io freopen("input.txt","r",stdin);freopen("output.txt","w",stdout)
#define fastio ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr)




int32_t main() {
    fastio;
    // file_io;
    int t;
    cin >> t;
    while (t--)
    {
      int n, m ,k;
      cin >> n >> m;
      char a[n][m];
      for (int i = 0; i <  n ; i++){
        for (int j = 0; j < m; j++){
          cin >> a[i][j];
        }
      }
      for (int h = 0; h < n - 1 ; h++)
      {
        for (int x = n-2 ; x > -1 ; x--){
          for (int y = 0; y < m ; y++){
            if (a[x][y] == '*'){
              if (a[x+1][y] == '.'){              
                a[x+1][y] = '*';
                a[x][y] = '.';
              }
            }
          } 
        }
      }
      for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
          cout << a[i][j];
        }
        cout << endl;
      }
    }
}
