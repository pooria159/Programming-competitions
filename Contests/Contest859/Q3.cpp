#include <bits/stdc++.h>
using namespace std;

#define int long long 
#define endl "\t"
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
    vector<bool> ans(t, true);
    string str = "abcdefghijklmnopqrstuvwxyz";
    for(int i = 0; i < t; i++){
        int n;
        cin >> n;
        string s;
        cin >> s;
        unordered_map<char, int> d;
        for (char c : str) {
            d[c] = -1;
        }
        int index = 0;
        for (char c : s) {
            if (d[c] == -1) {
                d[c] = index;
            } 
            else if ((index - d[c]) % 2 != 0) {
                ans[i] = false;
                break;
            }
            index++;
        }
    }
    for (bool a : ans) {
        cout << (a ? "YES" : "NO") << endl;
    }
}
