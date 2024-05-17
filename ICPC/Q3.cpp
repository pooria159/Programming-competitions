#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2005;

int n, m;
vector<pair<int, int>> adj[MAXN];
bool vis[MAXN];

int prim(int u) {
    int cnt = 0, cost = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, u});
    while(!pq.empty()) {
        int v = pq.top().second, w = pq.top().first;
        pq.pop();
        if(vis[v]) continue;
        vis[v] = true;
        cnt++;
        cost += w;
        for(auto edge: adj[v]) {
            int to = edge.first, weight = edge.second;
            pq.push({weight, to});
        }
    }
    return cost;
}

int main() {
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    int total_cost = 0;
    memset(vis, false, sizeof(vis));
    for(int i = 1; i <= n; i++) {
        if(!vis[i]) {
            total_cost += prim(i);
        }
    }

    vector<pair<int, int>> edges_to_remove;
    for(int u = 1; u <= n; u++) {
        for(auto edge: adj[u]) {
            int v = edge.first, w = edge.second;
            if(u < v && vis[u] != vis[v]) {
                edges_to_remove.push_back({u, v});
            }
        }
    }

    vector<pair<int, int>> edges_to_add;
    for(int u = 1; u <= n; u++) {
        if(vis[u]) {
            for(auto edge: adj[u]) {
                int v = edge.first, w = edge.second;
                if(vis[v]) {
                    edges_to_add.push_back({u, v});
                }
            }
        }
    }

    cout << edges_to_remove.size() << " " << edges_to_add.size() << endl;
    for(auto edge: edges_to_remove) {
        cout << edge.first << " " << edge.second << endl;
    }
    for(auto edge: edges_to_add) {
        cout << edge.first << " " << edge.second << endl;
    }

    return 0;
}