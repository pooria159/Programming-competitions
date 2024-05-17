#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

bool point_inside_polygon(double x, double y, const vector<pair<double, double>> &polygon) {
    int n = polygon.size();
    bool inside = false;

    for (int i = 0, j = n - 1; i < n; j = i++) {
        if (((polygon[i].second > y) != (polygon[j].second > y)) &&
            (x < (polygon[j].first - polygon[i].first) * (y - polygon[i].second) / (polygon[j].second - polygon[i].second) + polygon[i].first)) {
            inside = !inside;
        }
    }

    return inside;
}

int main() {
    int T, N, M;
    cin >> T;
    while (T--) {
        cin >> N >> M;

        vector<pair<double, double>> police(N);
        vector<pair<double, double>> thieves(M);

        for (int i = 0; i < N; ++i) {
            cin >> police[i].first >> police[i].second;
        }

        for (int i = 0; i < M; ++i) {
            cin >> thieves[i].first >> thieves[i].second;
        }

        int additional_police = M;

        for (int mask = 0; mask < (1 << N); ++mask) {
            vector<pair<double, double>> polygon;

            for (int i = 0; i < N; ++i) {
                if (mask & (1 << i)) {
                    polygon.push_back(police[i]);
                }
            }

            int caught_thieves = 0;
            for (const auto &thief : thieves) {
                if (point_inside_polygon(thief.first, thief.second, polygon)) {
                    caught_thieves++;
                }
            }

            additional_police = min(additional_police, M - caught_thieves);
        }

        cout << additional_police << endl;
    }

    return 0;
}