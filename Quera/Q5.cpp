#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> caps, tshirts, trousers;
    for (int i = 0; i < n; i++) {
        int t, c;
        cin >> t >> c;
        if (t == 1) caps.push_back(c);
        else if (t == 2) tshirts.push_back(c);
        else trousers.push_back(c);
    }
    sort(caps.begin(), caps.end());
    sort(tshirts.begin(), tshirts.end());
    sort(trousers.begin(), trousers.end());
    long long ans = 0;
    for (int cap : caps) {
        for (int tshirt : tshirts) {
            if (cap != tshirt) {
                ans += lower_bound(trousers.begin(), trousers.end(), max(cap, tshirt) + 1) - trousers.begin();
            }
        }
    }
    cout << ans << endl;
    return 0;
}
