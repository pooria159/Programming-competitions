#include<bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    vector<int> ans(t, 0);

    for (int k = 0; k < t; k++) {
        int n, d, a;
        cin >> n >> d >> a;

        string sa = to_string(a);

        int mx = stoi(to_string(d) + sa);

        if (n == 1) {
            int a1 = stoi(to_string(d) + sa);
            int a2 = stoi(sa + to_string(d));
            ans[k] = max(a1, a2);
            continue;
        }

        for (int i = 0; i < n; i++) {
            string tmp;
            if (i != 0 && i != n - 1) {
                tmp = sa.substr(0, i) + to_string(d) + sa.substr(i);
            } else if (i == 0) {
                tmp = to_string(d) + sa;
            } else {
                tmp = sa + to_string(d);
            }
            mx = max(mx, stoi(tmp));
        }

        ans[k] = mx;
    }

    for (int a : ans) {
        cout << a << endl;
    }

    return 0;
}
