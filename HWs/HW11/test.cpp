#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> graph(n + 1, vector<int>());
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    int k;
    cin >> k;
    vector<int> v(k), u(k);
    for (int i = 0; i < k; ++i) {
        cin >> v[i];
    }
    for (int i = 0; i < k; ++i) {
        cin >> u[i];
    }

    vector<vector<int>> dist(n + 1, vector<int>(n + 1, -1));
    for (int i = 1; i <= n; ++i) {
        queue<int> q;
        dist[i][i] = 0;
        q.push(i);
        while (!q.empty()) {
            int cur = q.front();
            q.pop();
            for (int neighbor : graph[cur]) {
                if (dist[i][neighbor] == -1) {
                    dist[i][neighbor] = dist[i][cur] + 1;
                    q.push(neighbor);
                }
            }
        }
    }

    int ans = -1;
    for (int i = 1; i <= n; ++i) {
        int cur = 0;
        for (int j = 0; j < k; ++j) {
            if (dist[v[j]][i] == -1 || dist[u[j]][i] == -1) {
                cur = -1;
                break;
            }
            cur += dist[v[j]][i] + dist[u[j]][i];
        }
        if (cur != -1) {
            if (ans == -1) {
                ans = cur;
            } else {
                ans = min(ans, cur);
            }
        }
    }

    cout << ans << endl;
    return 0;
}