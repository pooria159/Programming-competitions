#include <bits/stdc++.h>
using namespace std;

#define int long long 
#define endl "\n"
#define file_io freopen("input.txt","r",stdin);freopen("output.txt","w",stdout)
#define fastio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define pb push_back
#define PI 3.14159
#define pii pair<int,int>
map<int, int> mp;

int32_t main() {
    fastio;
    int t;
    cin >> t;
    vector<pair<int, int>> a(t);
    for(int i = 0; i < t; i++){
        int n;
        cin >> n;
        vector<int> dp1(n), dp2(n);
        for (int j = 0; j < n; j++)cin >> dp1[j];
        for (int j = 0; j < n; j++)cin >> dp2[j];
        int j = 0 , len = 0 , rarr = 0 ,larr = 0;
        while (j < n) {
            int l = j;
            while (j < n - 1 && dp2[j] <= dp2[j + 1]) {
                j++;
            }
            int r = j;
            if (r - l + 1 > len) {
                if (vector<int>(dp2.begin() + l, dp2.begin() + r + 1) == vector<int>(dp1.begin() + l, dp1.begin() + r + 1)) {
                } else {               
                    len = max(r - l + 1, len);
                    rarr = r;
                    larr = l;
                }
            }
            j++;
        }

        a[i] = make_pair(larr, rarr);
    }

    for (pii a : a) {
        cout << a.first + 1 << " " << a.second + 1 << endl;
    }

    return 0;
}