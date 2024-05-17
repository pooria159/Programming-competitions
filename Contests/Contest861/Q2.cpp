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

int func(vector<int>& arr, int n) {
    int sum = 0;
    for (int i = n - 1; i >= 0; i--) {
        sum += i * arr[i] - (n - 1 - i) * arr[i];
    }
    return sum;
}

int32_t main() {
    fastio
    int num_of_test;
    cin >> num_of_test;
    for (int t = 0; t < num_of_test; t++) {
        int n, x;
        cin >> n >> x;
        vector<vector<int>> m(n, vector<int>(x));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < x; j++) {
                cin >> m[i][j];
            }
        }
        vector<vector<int>> l(x);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < x; j++) {
                l[j].pb(m[i][j]);
            }
        }
        int ans = 0;
        for (auto i : l) {
            ans += func(std::sort(i), i.size());
        }
        cout << ans << endl;
    }
}
