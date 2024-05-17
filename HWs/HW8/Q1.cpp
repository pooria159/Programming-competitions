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
const int numeric = 1e5 + 9;
vector<int> adj[numeric] , rev_adj[numeric];
bool visited[numeric];
stack<int> stk;
int make_pow(int n , int y , int mod){return(!y ? 1 : (y & 1 ? n * make_pow((n * n) % mod , y/2 , mod) % mod : make_pow((n * n) % mod , y/2 , mod) % mod ));}


void dfs1(int u) {
    visited[u] = true;
    for(int v : adj[u]) {if (!visited[v]) dfs1(v);}
    stk.push(u);
}

void dfs2(int u) {
    visited[u] = true;
    for(int v : rev_adj[u]) {if (!visited[v]) dfs2(v);}
}

int result(int n) {
    memset(visited, false, sizeof(visited));
    for(int i = 1; i <= n; i++) {if(!visited[i]) dfs1(i);}
    memset(visited, false, sizeof(visited));
    int res = 0;
    while(!stk.empty()){
        int u = stk.top();
        stk.pop();
        if(!visited[u]){
            dfs2(u); res++;
        }
    }
    return res;
}

int32_t main() {
    fastio;
    int v, e;
    cin >> v >> e;
    FOR(i,0,e){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        rev_adj[v].push_back(u);
    }
    int res = result(v);
    cout << res << endl;
}