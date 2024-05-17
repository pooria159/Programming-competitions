#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    vector<vector<int>> adj(N + 1);
    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    bool found = false;
    for (int i = 1; i <= N && !found; i++) {
        for (int j = i + 1; j <= N && !found; j++) {
            int cnt = 0;
            for (int k : adj[i]) {
                if (k != j && find(adj[j].begin(), adj[j].end(), k) != adj[j].end()) {
                    cnt++;
                }
            }
            if (cnt >= 3) {
                found = true;
            }
        }
    }
    cout << (found ? "YES" : "NO") << endl;
    return 0;
}
