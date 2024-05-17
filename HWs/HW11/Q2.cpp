#include <bits/stdc++.h>
using namespace std;
#define int long long
#define uint unsigned long long
#define endl '\n'
#define file_io freopen("input.txt", "r", stdin);freopen("output.txt", "w", stdout)
#define fastio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define ff first
#define pb push_back
#define ss second
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
const int numeric = 2e5 + 500;
int parent[numeric] , tmp[numeric];
bool visited[numeric];
vector<int> present;
int edg;
int rightpos[numeric];
int left[numeric];
stack<int> stk;
int make_pow(int n , int y , int mod){return(!y ? 1 : (y & 1 ? n * make_pow((n * n) % mod , y/2 , mod) % mod : make_pow((n * n) % mod , y/2 , mod) % mod ));}


int32_t main() {
    fastio;
    int n, m;
    cin >> n >> m;
    vector<vector<int>> graph(n + 1);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    int k;
    cin >> k;
    vector<int> start(k), end(k);
    for (int i = 0; i < k; i++) {
        cin >> start[i];
    }
    for (int i = 0; i < k; i++) {
        cin >> end[i];
    }
    queue<vector<int>> q;
    q.push(start);
    vector<vector<int>> dist(1 << k, vector<int>(n + 1, -1));
    dist[0][start[0]] = 0;
    while (!q.empty()) {
        vector<int> cur = q.front();
        q.pop();
        int mask = 0;
        for (int i = 0; i < k; i++) {
            if (cur[i] == end[i]) {
                mask |= (1 << i);
            }
        }
        if (mask == (1 << k) - 1) {
            cout << dist[mask][cur[0]] << endl;
            return 0;
        }
        for (int u : graph[cur[0]]) {
            vector<int> next = cur;
            next[0] = u;
            for (int i = 1; i < k; i++) {
                if (cur[i] == u) {
                    next[i] = cur[0];
                }
            }
            int next_mask = 0;
            for (int i = 0; i < k; i++) {
                if (next[i] == end[i]) {
                    next_mask |= (1 << i);
                }
            }
            if (dist[next_mask][u] == -1) {
                dist[next_mask][u] = dist[mask][cur[0]] + 1;
                q.push(next);
            }
        }
    }
    cout << -1 << endl;
}
