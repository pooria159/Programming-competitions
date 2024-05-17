#include <iostream>
#include <vector>
#include <algorithm>
#include <bitset>

using namespace std;
#define int long long


bool is_good_array(const vector<int>& arr) {
    int m = arr.size() / 2;
    for (int mask = 1; mask < (1 << m); mask++) {
        int subseq_prod = 1, subseq_sum = 0;
        for (int i = 0; i < m; i++) {
            if ((mask >> i) & 1) {
                subseq_prod *= arr[i];
            } else {
                subseq_sum += arr[i];
            }
        }
        if (subseq_prod != subseq_sum) {
            return false;
        }
    }
    return true;
}

int min_distance(const vector<int>& p) {
    int n = p.size() / 2;
    int min_dist = numeric_limits<int>::max();
    vector<int> q(p.begin(), p.end());
    do {
        if (is_good_array(q)) {
            int dist = 0;
            for (int i = 0; i < 2 * n; i++) {
                dist += abs(q[i] - p[i]);
            }
            min_dist = min(min_dist, dist);
        }
    } while (next_permutation(q.begin(), q.end()));
    return min_dist;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> p(2 * n);
        for (int i = 0; i < 2 * n; i++) {
            cin >> p[i];
        }
        cout << min_distance(p) << endl;
    }
    return 0;
}
