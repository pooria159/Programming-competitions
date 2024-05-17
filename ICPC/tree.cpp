#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2005;

int n, m, cnt, ans1, ans2;
bool vis[MAXN], in_tree[MAXN][MAXN];
vector<int> adj[MAXN], rem, add;

void dfs(int u) {
    vis[u] = true;
    for (int v : adj[u]) {
        if (!vis[v]) {
            in_tree[u][v] = in_tree[v][u] = true;
            dfs(v);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(1);

    for (int i = 1; i <= n; i++) {
        for (int j = i+1; j <= n; j++) {
            if (!in_tree[i][j]) {
                if (vis[i] && vis[j]) {
                    rem.push_back(i);
                    rem.push_back(j);
                    ans1++;
                } else {
                    add.push_back(i);
                    add.push_back(j);
                    ans2++;
                }
            }
        }
    }

    cout << ans1 << " " << ans2 << "\n";
    for (int i = 0; i < ans1*2; i += 2) {
        cout << rem[i] << " " << rem[i+1] << "\n";
    }
    for (int i = 0; i < ans2*2; i += 2) {
        cout << add[i] << " " << add[i+1] << "\n";
    }

    return 0;
}
