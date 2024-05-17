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
const int MOD = 998244353;
const int num = 1e6+9; 
int make_pow(int x, int y, int mod) { return (!y ? 1 : (y & 1 ? x * make_pow((x * x) % mod, y / 2, mod) % mod : make_pow((x * x) % mod, y / 2, mod) % mod)); }
int dp[num];

int32_t main(){
    fastio;
    int n , left = 1, right = 1;
    cin >> n;
    dp[0] = 1;
    FOR(i,1,n+1) 
        dp[i] = (dp[i-1]*i) % MOD;
    int res = dp[n];
    FOR(h,1,n-1){
        right = dp[n-h];
        left *= (n - h + 1);
        left %= MOD;
        res += ((right-1) * left) % MOD;
        res %= MOD;
    }
    cout << res << endl;
}