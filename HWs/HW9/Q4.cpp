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
#define pb push_back
#define ss second
#define mk make_pair
#define pii pair<int, int>
int mod = 1e9 + 7;
const int numeric = 5e4 + 9;
int dist[numeric];
queue<int> q;
int make_pow(int n, int y, int mod) { return (!y ? 1 : (y & 1 ? n * make_pow((n * n) % mod, y / 2, mod) % mod : make_pow((n * n) % mod, y / 2, mod) % mod)); }

void bfs(int n, int t, vector<pii> adj[], bool flag[], int &cnt, int k){
    bool visited[n];
    fill(visited, visited + n, false);
    q.push(t);
    dist[t] = 0;
    if (flag[t] == false){cnt--;flag[t] = true;}
    while (!q.empty())
    {
        int u = q.front();
        // cout << u << endl;
        // cout << "--------------" << endl;
        q.pop();
        visited[t] = false;
        for (auto edge : adj[u]){
            int v = edge.ff;
            int w = edge.ss;
            if(dist[v] > dist[u] + w && visited[v]==false){
                visited[v] = true;
                dist[v] = dist[u] + w;
                q.push(v);
                if(flag[v] == false){
                    cnt--;flag[v] = true;
                }
            }
        }
    }
}

int32_t main()
{
    fastio;
    int n, m, t, k;
    cin >> n >> m >> t >> k;
    int cnt = n;
    bool flag[n];
    fill(flag, flag + n, false);
    fill(dist, dist + n, k);
    vector<pii> adj[n];
    while (m--)
    {
        int u, v, w;
        cin >> u >> v >> w;
        u--;
        v--;
        adj[u].pb({v, w});
        adj[v].pb({u, w});
    }
    for (int j = 0; j < t; j++)
    {
        int x;
        cin >> x;
        x--;
        bfs(n, x, adj, flag, cnt, k);
        cout << cnt << endl;
    }
}
