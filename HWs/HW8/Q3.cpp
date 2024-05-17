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
vector<int> adj[numeric];
int dist[numeric];
bool visited[numeric];
int depth[numeric], parent[numeric];
int make_pow(int n , int y , int mod){return(!y ? 1 : (y & 1 ? n * make_pow((n * n) % mod , y/2 , mod) % mod : make_pow((n * n) % mod , y/2 , mod) % mod ));}


void bfs(int t){
    queue<int> q;
    q.push(t);
    dist[t] = 0;
    while(!q.empty()){
        int u = q.front(); 
        q.pop();
        for(int v : adj[u]){
            if(dist[v] == -1){
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }
}

int32_t main() {
    fastio;
    int T; 
    cin >> T;
    while (T--){
        int n, m, s, t;
        cin >> n >> m >> s >> t;
        FOR(i,1,n+1){
            adj[i].clear();
            dist[i] = -1;
        }
        FOR(i,0,m){
            int u, v; 
            cin >> u >> v;
            adj[u].pb(v);
        }
        bfs(t);
        cout << dist[s] << endl;
    }
}
