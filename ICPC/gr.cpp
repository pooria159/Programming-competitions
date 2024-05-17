#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2005;

int n, m;
vector<int> adj[MAXN];

bool is_complete_bipartite() {
    for(int i = 1; i <= n; i++) {
        for(int j = i+1; j <= n; j++) {
            if(find(adj[i].begin(), adj[i].end(), j) == adj[i].end()) { // i and j are not adjacent
                for(int k = j+1; k <= n; k++) {
                    if(find(adj[i].begin(), adj[i].end(), k) == adj[i].end() && // i and k are not adjacent
                       find(adj[j].begin(), adj[j].end(), k) == adj[j].end()) { // j and k are not adjacent
                        int cnt_a = 0, cnt_b = 0;
                        for(int u: adj[i]) {
                            if(find(adj[j].begin(), adj[j].end(), u) != adj[j].end()) cnt_a++;
                        }
                        for(int u: adj[k]) {
                            if(find(adj[j].begin(), adj[j].end(), u) != adj[j].end()) cnt_b++;
                        }
                        if(cnt_a == cnt_b && cnt_a + cnt_b == adj[j].size()) {
                            return true; // found a K2,3 subgraph
                        }
                    }
                }
            }
        }
    }
    return false; // no K2,3 subgraph found
}

int main() {
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    if(is_complete_bipartite()) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
    return 0;
}