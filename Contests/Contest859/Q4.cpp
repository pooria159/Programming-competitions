#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\t"
#define file_io                       \
    freopen("input.txt", "b", stdin); \
    freopen("output.txt", "w", stdout)
#define fastio               \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0)
#define pb push_back
#define PI 3.14159
#define pii pair<int, int>
map<int, int> mp;

int32_t main()
{
    fastio;
    int t;
    cin >> t;
    vector<bool> mark;
    for (int i = 0; i < t; i++)
    {
        int n, ans;
        cin >> n >> ans;
        vector<int> arr(n);
        for (int j = 0; j < n; j++)
            cin >> arr[j];
        vector<int> res(n);
        res[0] = arr[0];
        for (int j = 1; j < n; j++)
        {
            res[j] = res[j - 1] + arr[j];
        }
        for (int j = 0; j < ans; j++)
        {
            int a, b, c;
            cin >> a >> b >> c;
            a--;
            b--;
            int temp = 0;
            temp += (b - a + 1) * c;
            if (a != 0){temp += res[a - 1];}
            if (b != n - 1){temp += res[n - 1] - res[b];}
            if (temp % 2 == 0){mark.push_back(false);}
            else{mark.push_back(true);}
        }
    }
    for(bool a : mark){cout << (a ? "YES" : "NO") << endl;}
}
