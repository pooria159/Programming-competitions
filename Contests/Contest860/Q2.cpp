#include <bits/stdc++.h>
using namespace std;

#define int long long 
#define endl "\t"
#define file_io freopen("input.txt","r",stdin);freopen("output.txt","w",stdout)
#define fastio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define pb push_back
#define PI 3.14159
#define pii pair<int,int>

int32_t main() {
    fastio;
    int t;
    cin >> t;
    while(t--){
        int m;
        cin >> m;
        bool pos = true;
        map<int, int> mp;
        vector<vector<int>> a;
        vector<string> arr(m, "0");
        for (int j = 0; j < m; j++){
            int n;
            cin >> n;
            vector<int> tmp(n);
            for (int h = 0; h < n; h++){
                cin >> tmp[h];
            }
            a.pb(tmp);
        }
        for (int j = 1; j <= m; j++){
            int index = m - j;
            bool newpos = false;
            for (int x : a[index]) {
                int pt = mp[x];
                if (pt == 0){
                    mp[x] = index;
                    if (!newpos) {
                        arr[index] = to_string(x);
                        newpos = true;
                    }
                }
            }
            if (!newpos) {
                pos = false;
                break;
            }
        }
        if (!pos) {
            cout << -1 << endl;
        } 
        else {
            for (string s : arr) {
                cout << s << " ";
            }
            cout << endl;
        }
    }
    return 0;
}
