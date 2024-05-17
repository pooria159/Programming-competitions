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
const int numeric = 200005;
vector<int> tmp[numeric];
bool visited[numeric];
int dist[numeric];
int make_pow(int n , int y , int mod){return(!y ? 1 : (y & 1 ? n * make_pow((n * n) % mod , y/2 , mod) % mod : make_pow((n * n) % mod , y/2 , mod) % mod ));}


int farthestVertex, maxDist;
void dfs(int u, int d) {
    visited[u] = true;
    dist[u] = d;
    if(d > maxDist){farthestVertex = u; maxDist = d;}
    for(int v : tmp[u]) {
        if (!visited[v])
            dfs(v, d+1);
    }
}

int32_t main(){
    fastio;
    int n;
    cin >> n;
    FOR(i,1,n){
        int u, v;
        cin >> u >> v;
        tmp[u].pb(v); tmp[v].pb(u);
    }
    dfs(1, 0);
    maxDist = 0;
    FOR(i,1,n+1){visited[i] = false; dist[i] = 0;}
    dfs(farthestVertex, 0);
    cout << maxDist << endl;
}