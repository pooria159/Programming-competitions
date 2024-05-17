#include <bits/stdc++.h>
using namespace std;
#define int long long
#define uint unsigned long long
#define endl "\n"
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
#define maxres *max_element
int mod = 1e9 + 7;
const int N = 18;
double res[N+100];
double mrx[N+100][N+100];
double dp[1 << N];

int32_t main(){
	fastio;
	int n, m, k;
    cin >> n >> m >> k;
	vector<int> a;
	FOR(i,1,n+1){
		cin >> res[i];
		dp[1 << (i-1)] = res[i];
	}
	FOR(i,1,k+1){
		int x, y, c; 
        cin >> x >> y >> c;
		mrx[x][y] = c;
	}
	FOR(mask,0,(1<<n)){
		FOR(i,1,n+1){
			if((mask & (1 << (i-1)))==false){
				int next = mask ^ (1 << (i-1));
				FOR(j,1,n+1){
					(mask & (1 << (j-1))) ? dp[next] = max(dp[next], dp[mask] + mrx[j][i] + res[i]) : 1 ;
				}
			}
		}
	}
	FOR(mask,0,(1 << n))
		if (__builtin_popcount(mask) == m)a.pb(dp[mask]);
	cout << *max_element(a.begin(),a.end()) << endl;
}