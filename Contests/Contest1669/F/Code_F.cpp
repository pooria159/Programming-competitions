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
      int n , res = 0 , mark = 0,
      alice = 0 , bob = 0,
      nb = 0 , na = 0;
      cin >> n;
      int a[n] = {0};
      for (int i = 0; i < n; i++){cin >> a[i];}
      int start = 0 , end = n-1;
      while(start <= end)
      {
        if(alice > bob){
          bob += a[end];
          nb++;
          end--;
        }
        else if(alice < bob){
          alice += a[start];
          na++;
          start++;
        }
        else if(a[start] < a[end]){
          alice += a[start];
          na++;
          start++;
        }
        else if(a[start] >= a[end]){
          bob += a[end];
          nb++;
          end--;
        }
        if(bob == alice){
          res = max(res,na+nb);
          mark = 1;
        }
      }
      if(mark)
      {
        cout << res << endl;
      }
      else
      {
        cout << 0 << endl;
      }
    }
}
