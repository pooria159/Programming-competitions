#include <bits/stdc++.h>
using namespace std;

#define int long long 
#define endl "\t"
#define file_io freopen("input.txt","r",stdin);freopen("output.txt","w",stdout)
#define fastio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define pb push_back
#define PI 3.14159
#define pii pair<int,int>
const int numeric = 100005;
vector<int> a[numeric];


int32_t main() {
    int k, n;
    cin >> k >> n;
    int64_t ans = 0;
    if (k > 1) {
        ans += 2 * (n / k) * (k - 1);
        int rem = n % k;
        ans += min(rem, 2 * (k - 1));
    } else {
        ans = n;
    }
    cout << ans << endl;
    return 0;
}
