#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        int cnt = 0;
        bool found = false;

        for (int i = 0; i < n; i++) {
            if (a[i] == cnt) {
                cnt++;
            } else if (cnt == 0 && a[i] == 0) {
                cnt++;
            } else if (cnt > 0 && a[i] == cnt && i < n - 1 && a[i+1] != cnt+1) {
                cnt++;
            } else if (!found) {
                int j = i;
                while (j < n && a[j] == a[i]) {
                    j++;
                }
                found = true;
                i = j - 1;
            }
        }

        if (found || cnt < n) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }

    return 0;
}