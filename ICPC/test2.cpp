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
        vector<bool> state(n - 2);
        char last_char = s[n - 1];
        for (int j = n - 3; j >= 0; j--) {
            char curr_char = s[j];
            if (curr_char == s[j + 1]) {
                state[j] = true;
            } else if (j + 2 < n && curr_char == s[j + 2]) {
                state[j] = true;
            } else if (last_char == curr_char) {
                state[j] = true;
                last_char = s[j + 1];
            } else {
                last_char = curr_char;
            }
        }
        while (q--) {
            int l, r;
            cin >> l >> r;
            l--;
            r--;
            bool flag = false;
            for (int k = l; k <= r - 2; k++) {
                if (state[k] && state[k + 1] && state[k + 2]) {
                    flag = true;
                    break;
                }
            }
            cout << (flag ? "YES" : "NO") << endl;
        }
    }

    return 0;
}