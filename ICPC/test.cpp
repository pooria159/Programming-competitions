#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, q;
        cin >> n >> q;
        string s;
        cin >> s;
        n = s.length();
        vector<bool> state(n - 2);
        for (int j = 0; j < n - 2; j++) {
            if (s[j] == s[j + 1]) {
                state[j] = true;
                continue;
            }
            if (s[j] == s[j + 2]) {
                state[j] = true;
                continue;
            }
            if (s[j + 1] == s[j + 2]) {
                state[j + 1] = true;
                continue;
            }
        }
        for (int j = 0; j < q; j++) {
            int l, r;
            cin >> l >> r;
            l--;
            r--;
            bool flag = false;
            for (int k = l; k < r - 1; k++) {
                if (state[k] && l <= k && r >= k + 2) {
                    flag = true;
                    break;
                }
            }
            cout << (flag ? "YES" : "NO") << endl;
        }
    }

    return 0;
}
