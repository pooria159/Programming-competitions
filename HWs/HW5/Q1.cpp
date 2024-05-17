#include <bits/stdc++.h>
using namespace std;
#define int long long
#define uint unsigned long long
#define endl "\t"
#define file_io                       \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout)
#define fastio               \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0)
#define ff first
#define ss second
#define pb push_back
#define mk make_pair
#define pii pair<int, int>
#define ABS(x) ((x) < 0 ? -(x) : (x))
#define SORT(v) sort(v.begin(), v.end())
#define REV(v) reverse(v.begin(), v.end())
#define SQR(a) ((a) * (a))
#define FOR(i, x, n) for (int i = x; i < n; i++)
#define ROF(i, x, n) for (int i = n - 1; i >= x; i--)
int mod = 1e9 + 7;

const int N = 18;
double mrx[N][N];
double dp[1 << N];
int32_t main()
{
    fastio;
    int t;
    cin >> t;
    FOR(i, 0, t)
    {
        FOR(j, 0, t)
        {
            cin >> mrx[i][j];
        }
    }
    dp[(1 << t) - 1] = 1;
    ROF(mask, 0, (1 << t))
    {
        int ans = 0;
        FOR(i, 0, t)
        if (mask & (1 << i)) ans++;
        double prob = (ans * (ans - 1)) / 2;
        FOR(i, 0, t)
        {
            FOR(j, 0, t)
            {
                if ((mask & (1 << i)) == 0)
                    continue;
                if ((mask & (1 << j)) == 0)
                    continue;
                int next = mask ^ (1 << j);
                dp[next] += (dp[mask] * mrx[i][j]) / prob;
            }
        }
    }
    FOR(i, 0, t)
        cout << fixed << setprecision(6) << dp[1 << i] << " ";
}
