#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int n, m;
vector<vector<int>> adj;
vector<bool> visited;
vector<int> low, dfn;
stack<int> st;
int timestamp = 0;
int ans = 0;

void tarjan(int u) {
    low[u] = dfn[u] = ++timestamp;
    st.push(u);
    visited[u] = true;
    for (int v : adj[u]) {
        if (!dfn[v]) {
            tarjan(v);
            low[u] = min(low[u], low[v]);
        } else if (visited[v]) {
            low[u] = min(low[u], dfn[v]);
        }
    }
    if (low[u] == dfn[u]) {
        ans++;
        int v;
        do {
            v = st.top(); st.pop();
            visited[v] = false;
        } while (u != v);
    }
}

int main() {
    cin >> n >> m;
    adj.resize(n + 1);
    visited.resize(n + 1);
    low.resize(n + 1);
    dfn.resize(n + 1);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }
    for (int i = 1; i <= n; i++) if (!dfn[i]) tarjan(i);
    cout << n - ans << endl;
    return 0;
}
