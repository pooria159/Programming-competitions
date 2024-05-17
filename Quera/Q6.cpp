#include <bits/stdc++.h>
using namespace std;
#define int long long
#define uint unsigned long long
#define endl '\n'
#define file_io                       \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout)
#define fastio               \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0)
#define pb push_back
#define mk make_pair
#define pii pair<int, int>
#define ABS(n) ((n) < 0 ? -(n) : (n))
#define SORT(v) sort(v.begin(), v.end())
#define REV(v) reverse(v.begin(), v.end())
#define SQR(a) ((a) * (a))
#define FOR(i, n, p) for (int i = n; i < p; i++)
#define ROF(i, n, p) for (int i = p - 1; i > n; i--)
#define FOOR(i, n, p) for (int i = n; i < p; i += 2)

int32_t main() {
    fastio
    int t;
    cin >> t;
    vector<int> ans(t);

    for (int i = 0; i < t; i++) {
        int n, m;
        cin >> n >> m;

        vector<vector<int>> arr(n, vector<int>(m));
        vector<vector<int>> dp(n, vector<int>(m));

        for (int j = 0; j < n; j++) {
            for (int k = 0; k < m; k++) {
                cin >> arr[j][k];
            }
        }

        dp[0][0] = arr[0][0];

        for (int j = 1; j < m; j++) {
            dp[0][j] = dp[0][j - 1] + arr[0][j];
        }

        for (int j = 1; j < n; j++) {
            dp[j][0] = dp[j - 1][0] + arr[j][0];
        }

        for (int j = 1; j < n; j++) {
            for (int k = 1; k < m; k++) {
                dp[j][k] = max(dp[j - 1][k], dp[j][k - 1]) + arr[j][k];
            }
        }

        ans[i] = dp[n - 1][m - 1];
    }

    for (int a : ans) {
        cout << a << endl;
    }

    return 0;
}

