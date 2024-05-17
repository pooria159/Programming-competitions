#include <bits/stdc++.h>
using namespace std;

#define int long long 
#define endl "\n"
// #define file_io freopen("input.txt","red",stdin);freopen("output.txt","w",stdout)
#define fastio ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr)


bool State(int red, int blue , bool flag = true){
  if ((red > 0 and blue == 0) or (red == 0 and blue > 0))
  {
    flag = false;
  }
  return flag;
}

int32_t main() {
    fastio;
    int t;
    cin >> t;
    while (t--){
        int n , red = 0, blue = 0;
        cin >> n;
        bool mark = true , flag = true;
        string str;
        cin >> str;
        for (int i = 0; i < n; i++){
        if(str[i] == 'R'){
            red++;
        } 
        else if(str[i] == 'B'){
            blue++;
        } 
        else{
            mark &= State(red, blue , flag);
            red = 0; 
            blue = 0;
        }
    }
    mark &= State(red, blue , flag);
    if (mark) {
      cout << "YES" << endl;
    } 
    else {
      cout << "NO" << endl;
    }
  }
}



