#include <bits/stdc++.h>
using namespace std;

#define int long long 
#define endl "\t"
#define file_io freopen("input.txt","r",stdin);freopen("output.txt","w",stdout)
#define fastio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define pb push_back
#define PI 3.14159
#define pii pair<int,int>


void solve() {
    int n;
    cin >> n;
    vector<pair<int, int>> candies(n);
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        candies[i] = make_pair(a, b);
    }

    vector<int> divisors(n);
    for (int i = 0; i < n; i++) {
        int a = candies[i].first;
        int b = candies[i].second;
        int div = 1;
        for (int j = 1; j < sqrt(a)/2; j++) {
            if (a % j == 0) {
                if (a / j >= n) {
                    div = max(div, j);
                }
                if (j >= n) {
                    div = max(div, a / j);
                }
            }
        }
        divisors[i] = div;
    }

    vector<int> costs(n);
    for (int i = 0; i < n; i++) {
        int a = candies[i].first;
        int b = candies[i].second;
        int di = divisors[i];
        int c = b * di;
        costs[i] = c;
    }
    vector<int> groups;
    int cur_cost = -1;
    for (int i = 0; i < n; i++) {
        int c = costs[i];
        if (c != cur_cost) {
            cur_cost = c;
            groups.push_back(1);
        } else {
            groups.back() += 1;
        }
    }

    cout << groups.size() << endl;
}

int32_t main() {
    fastio;
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}
