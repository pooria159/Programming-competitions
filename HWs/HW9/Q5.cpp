#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

struct Node {
    int x, y, cost;
    Node(int _x, int _y, int _cost) : x(_x), y(_y), cost(_cost) {}
};

struct Compare {
    bool operator()(const Node& n1, const Node& n2) {
        return n1.cost > n2.cost;
    }
};

int dijkstra(const vector<vector<int>>& table, const vector<vector<int>>& embassies, int sx, int sy, int ex, int ey) {
    int n = table.size();
    int m = table[0].size();
    vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
    priority_queue<Node, vector<Node>, Compare> pq;

    dist[sx][sy] = 0;
    pq.push(Node(sx, sy, 0));

    while (!pq.empty()) {
        Node curr = pq.top();
        pq.pop();

        int x = curr.x;
        int y = curr.y;
        int cost = curr.cost;

        if (x == ex && y == ey) {
            return cost;
        }

        if (cost > dist[x][y]) {
            continue;
        }

        // Check neighboring cells
        vector<pair<int, int>> neighbors = {{x+1, y}, {x-1, y}, {x, y+1}, {x, y-1}};
        for (const auto& neighbor : neighbors) {
            int nx = neighbor.first;
            int ny = neighbor.second;

            if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
                int travel_cost = (table[nx][ny] == 0) ? 0 : 1;

                if (cost + travel_cost < dist[nx][ny]) {
                    dist[nx][ny] = cost + travel_cost;
                    pq.push(Node(nx, ny, dist[nx][ny]));
                }
            }
        }

        // Check embassies
        int country = embassies[x][y];
        if (country != 0) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    if (embassies[i][j] == country && (i != x || j != y)) {
                        int travel_cost = (table[i][j] == 0) ? 0 : 1;

                        if (cost + travel_cost < dist[i][j]) {
                            dist[i][j] = cost + travel_cost;
                            pq.push(Node(i, j, dist[i][j]));
                        }
                    }
                }
            }
        }
    }

    return -1;  // Destination is not reachable
}

int main() {
    int n, m, k;
    cin >> n >> m >> k;

    int sx, sy, ex, ey;
    cin >> sx >> sy >> ex >> ey;

    vector<vector<int>> table(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> table[i][j];
        }
    }

    vector<vector<int>> embassies(n, vector<int>(m));
    for (int i = 0; i < k; i++) {
        int x, y, p;
        cin >> x >> y >> p;
        embassies[x-1][y-1] = p;
    }

    int min_cost = dijkstra(table, embassies, sx-1, sy-1, ex-1, ey-1);
    cout << min_cost << endl;

    return 0;
}
