#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"
#define file_io freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout)
#define fastio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define pb push_back
#define PI 3.14159
#define pii pair<int, int>
int mod = pow(10,9)+7;
int maxn = pow(10,5)+7;

int32_t main(){
    fastio;
    string s;
    cin >> s;
    vector<int> up(maxn),low(maxn);
    (s.back() >= 'A' && s.back() <= 'Z') ? up[s.length()-1] = 1 : 0;
    (s.front() >= 'a' && s.front() <= 'z') ? low[0] = 1 : 0;
    for(int i = 1; i < s.length(); i++){
        int j = s.length()-1-i;
        (s[j] >= 'A' && s[j] <= 'Z') ? up[j] = up[j+1] + 1 : up[j] = up[j+1];
        (s[i] >= 'a' && s[i] <= 'z') ? low[i] = low[i-1] + 1 : low[i] = low[i-1];
    }
    int ans = up[0];
    for(int i = 0; i < s.length(); i++){
        int tmp = low[i] + up[i+1];
        (tmp < ans)? ans = tmp:1;
    }
    cout << ans << endl;
}
