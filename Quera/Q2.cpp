#include <bits/stdc++.h>
using namespace std;
#define int long long
#define uint unsigned long long
#define endl '\n'
#define file_io                       \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout)
#define fastio               \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0)
#define pb push_back
#define mk make_pair
#define pii pair<int, int>
#define ABS(n) ((n) < 0 ? -(n) : (n))
#define SORT(v) sort(v.begin(), v.end())
#define REV(v) reverse(v.begin(), v.end())
#define SQR(a) ((a) * (a))
#define FOR(i, n, p) for (int i = n; i < p; i++)
#define ROF(i, n, p) for (int i = p - 1; i > n; i--)
#define FOOR(i, n, p) for (int i = n; i < p; i += 2)



int32_t main() {
    fastio;
    int n;
    cin >> n;
    vector<int> caps, shirts, trousers;
    for (int i = 0; i < n; i++) {
        int t, c;
        cin >> t >> c;
        if (t == 1) caps.push_back(c);
        else if (t == 2) shirts.push_back(c);
        else trousers.push_back(c);
    }
    long long ans = 0;
    for (int cap : caps) {
        for (int shirt : shirts) {
            if (cap == shirt) continue;
            for (int trouser : trousers) {
                if (cap != trouser && shirt != trouser) ans++;
            }
        }
    }
    cout << ans << endl;
    return 0;
}
