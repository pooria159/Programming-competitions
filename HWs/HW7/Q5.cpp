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
#define ABS(n) ((n) < 0 ? -(n) : (n))
#define SORT(v) sort(v.begin(), v.end())
#define REV(v) reverse(v.begin(), v.end())
#define SQR(a) ((a) * (a))
#define FOR(i, n, p) for (int i = n; i < p; i++)
#define ROF(i, n, p) for (int i = p - 1; i > n; i--)
#define FOOR(i, n , p) for (int i = n ; i < p; i+=2)
#define maxres *max_element
int mod = 1e9 + 7;
const int numeric = 100005;
int make_pow(int n , int y , int mod){return(!y ? 1 : (y & 1 ? n * make_pow((n * n) % mod , y/2 , mod) % mod : make_pow((n * n) % mod , y/2 , mod) % mod ));}
const int L = 20;

int n , f , s;
int d[numeric];
int pr[L][numeric];
vector<int> g[numeric];

void dfs(int v, int p = -1){
    d[v] = (p != -1 ? d[p] + 1 : 0);
    for (auto u : g[v]) {
        if(u != p) dfs(u, v);
    }
}

void init(int v, int p = -1){
    d[v] = (p != -1 ? d[p] + 1 : 0);
    pr[0][v] = (p == -1 ? v : p);
    FOR(i,1,L) pr[i][v] = pr[i - 1][pr[i - 1][v]];
    for (auto u : g[v]) {
        if (u != p) init(u, v);
    }
}
void up(int &v, int depth) {ROF(i,-1,L) if (d[pr[i][v]] >= depth) v = pr[i][v];}

int calc(int u, int v) {
    if (d[u] > d[v]) up(u, d[v]);
    else up(v, d[u]);
    ROF(i,-1,L){
        if (pr[i][v] != pr[i][u]) {
            v = pr[i][v]; u = pr[i][u];
        }
    }
    return (u != v ? pr[0][v] : v);
}

int dist(int u, int v) {return d[u] + d[v] - 2 * d[calc(u, v)];}

int32_t main(){
    fastio;
    cin >> n;
    for (int i = 0; i + 1 < n; i++){
        int u, v; cin >> u >> v;
        u--, v--; g[u].pb(v); g[v].pb(u);
    }
    dfs(0);
    FOR(i,0,n) if(d[i] > d[f]) f = i;
    dfs(f);
    FOR(i,0,n) if (d[i] > d[s]) s = i;
    init(0);
    int ans[n];
    FOR(i,0,n) ans[i] = 0;
    FOR(i,0,n) ans[max(dist(f, i), dist(s, i)) - 1]++;
    int res = 1;
    FOR(i,0,n){
        cout << res << ' ';
        res += ans[i];
        res = min(res, n);
    }cout << endl;
}