#include <bits/stdc++.h>
using namespace std;
#define int long long
#define uint unsigned long long
#define endl '\n'
#define file_io freopen("input.txt", "r", stdin);freopen("output.txt", "w", stdout)
#define fastio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define ff first
#define ss second
#define pb push_back
#define mk make_pair
#define pii pair<int, int>
#define ABS(x) ((x) < 0 ? -(x) : (x))
#define SORT(v) sort(v.begin(), v.end())
#define REV(v) reverse(v.begin(), v.end())
#define SQR(a) ((a) * (a))
#define FOR(i, x, p) for (int i = x; i < p; i++)
#define ROF(i, x, p) for (int i = p - 1; i > x; i--)
#define FOOR(i, x, p) for (int i = x; i < p; i += 2)
#define maxres *max_element
int mod = 1e9 + 7;
int make_pow(int x, int y, int mod) { return (!y ? 1 : (y & 1 ? x * make_pow((x * x) % mod, y / 2, mod) % mod : make_pow((x * x) % mod, y / 2, mod) % mod)); }
int ans = 0;
void dfs(int v, int x, vector<vector<int>>& res, vector<int> a[], int k) {
    res[v][0] = 1;
    FOR(i,0,a[v].size()){
        int check = a[v][i];
        if(check != x){dfs(check, v, res, a, k);
            FOR(j,1,k+1) ans = ans + res[check][j - 1] * res[v][k - j];
            FOR(j,1,k+1) res[v][j] = res[v][j] + res[check][j - 1];
        }
    }
}

int32_t main() {
    fastio;
    int n, k;
    cin >> n >> k;
    vector<int> a[n+10];
    vector<vector<int>> dp(n+1, vector<int>(510));
    FOR(i,0,n-1){
        int x, y;
        cin >> x >> y;
        a[x].pb(y); a[y].pb(x);
    }
    vector<vector<int>> res(n+10, vector<int>(k+1));
    dfs(1, 0, res, a, k);
    cout << ans << endl;
}