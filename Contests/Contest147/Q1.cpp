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
    vector<int> a(t, 0);
    for (int i = 0; i < t; i++){
        string s;
        cin >> s;
        if (s[0] == '0'){
            a[i] = 0;
            continue;
        }
        int res = count(s.begin(), s.end(), '?');
        (s[0] != '?') ? a[i] = pow(10, res) : a[i] = pow(10, res - 1) * 9;
    }
    for (int i = 0; i < t; i++) {cout << a[i] << endl;}
}