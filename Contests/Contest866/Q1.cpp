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
    for (int i = 0; i < t; i++) {
        string s;
        cin >> s;
        int ans = 0;
        if (s[0] == '_') {
            ans = 1;
        }
        for (int i = 0; i < s.length() - 1; i++) {
            if (s[i] == '_' && s[i+1] != '^') {
                ans++;
            }
        }
        if (s[s.length() - 1] == '_') {
            ans++;
        }
        if (s == "^") {
            ans = 1;
        }
        cout << ans << endl;
        }
}