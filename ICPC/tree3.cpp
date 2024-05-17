#include <iostream>
#include <vector>
using namespace std;

void dfs(int v, vector<vector<int>>& adj_list, vector<bool>& visited, vector<int>& mode, int parent, vector<pair<int,int>>& remove_list) {
    visited[v] = true;
    mode[v] = 1;
    for (int a : adj_list[v]) {
        if (!visited[a]) {
            dfs(a, adj_list, visited, mode, v, remove_list);
        } else if (mode[a] == 1 && a != parent) {
            remove_list.push_back(make_pair(v, a));
        }
    }
    mode[v] = 2;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj_list(n);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj_list[a - 1].push_back(b - 1);
        adj_list[b - 1].push_back(a - 1);
    }

    vector<pair<int,int>> remove_list;
    int start = 0;
    int parent = -1;
    vector<bool> visited(n);
    vector<pair<int,int>> add_list;
    vector<int> mode(n);
    int cnt = n;

    while (cnt > 0) {
        if (cnt != n) {
            int next_start = -1;
            for (int i = 0; i < n; i++) {
                if (!visited[i]) {
                    next_start = i;
                    break;
                }
            }
            add_list.push_back(make_pair(start, next_start));
            parent = start;
            start = next_start;
        }
        dfs(start, adj_list, visited, mode, parent, remove_list);
        cnt = 0;
        for (int i = 0; i < n; i++) {
            if (!visited[i]) cnt++;
        }
    }

    int a = remove_list.size();
    int b = add_list.size();
    cout << a << " " << b << endl;
    for (int i = 0; i < a; i++) {
        cout << remove_list[i].first + 1 << " " << remove_list[i].second + 1 << endl;
    }
    for (int i = 0; i < b; i++) {
        cout << add_list[i].first + 1 << " " << add_list[i].second + 1 << endl;
    }

    return 0;
}
