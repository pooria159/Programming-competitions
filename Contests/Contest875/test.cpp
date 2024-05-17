#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n), b(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        for (int i = 0; i < n; i++) {
            cin >> b[i];
        }
        unordered_map<int, int> cnt;
        long long ans = 0;
        for (int i = 0; i < n; i++) {
            ans += cnt[a[i] * a[i] - b[i]];
            cnt[a[i] * a[i] - b[i]]++;
        }
        cout << ans << endl;
    }
    return 0;
}
