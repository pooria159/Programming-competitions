#include <bits/stdc++.h>
using namespace std;

#define int long long 
#define endl "\n"
// #define file_io freopen("input.txt","red",stdin);freopen("output.txt","w",stdout)
#define fastio ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr)
map<string,int>mp;



int32_t main() {
    fastio;
    int t;
    cin >> t;
    while (t--)
    {
      mp.clear();
      int n , res = 0;
      cin >> n;
      for (int i = 0; i < n; i++)
      {
        string str;
        cin >> str;
        for (int j = 0; j < str.length(); j++)
        {
          for (char h = 'a'; h <= 'k'; h++)
          {
            if (str[j] == h)
            {
              continue;
            }
            string s = str;
            s[j] = h;
            res = res + mp[s];
          }
        }
        mp[str]++;
      }
      cout << res << endl; 
    }
}

