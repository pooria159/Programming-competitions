#include <bits/stdc++.h>
using namespace std;

#define int long long 
#define endl "\n"
#define file_io freopen("input.txt","r",stdin);freopen("output.txt","w",stdout)
#define fastio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define pb push_back
#define PI 3.14159
#define pii pair<int,int>
map<int, int> mp;


int32_t main() {
    fastio;
    int t;
    cin >> t;
    for (int i = 0; i < t; i++){
        int n, d , pos;
        cin >> n >> d;
        string s;
        cin >> s;
        pos = n;
        for (int j = 0 ; j < n ; j++) {
            if (s[j] < char(d+'0')){
                pos = j-1;
            } else {
                continue;
            }
        }
        string ans = s.substr(0, pos) + char(d+'0') + s.substr(pos);
        cout << ans << endl;
    }
    return 0;
}
