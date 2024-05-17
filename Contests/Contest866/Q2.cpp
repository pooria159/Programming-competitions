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
    int t;
    cin >> t;
    vector<int> ans(t, 0);
    for (int i = 0; i < t; i++) {
        string s;
        cin >> s;
        string copyst = s;
        int n = s.size();
        if (count(s.begin(), s.end(), '1') == n) {
            ans[i] = n * n;
            continue;
        }
        while (copyst[0] != '0') {copyst = copyst.substr(n - 1, 1) + copyst.substr(0, n - 1);}
        int tmp = 0, curr = 0;
        for (char c : copyst) {
            if (c == '1') {tmp++;} 
            else 
            {
                curr = max(tmp, curr);
                tmp = 0;
            }
        }
        (tmp != 0) ? curr = max(tmp, curr) : 1;
        int mul = curr * 1;
        int buff = mul;
        for (int j = curr; j > 0; j--)
        {
            mul = (curr + 1 - j) * j;
            buff = max(mul, buff);
        }
        ans[i] = buff;
    }
    for (int a : ans) {cout << a << endl;}
}