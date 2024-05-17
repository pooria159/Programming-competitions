#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"
#define file_io freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout)
#define fastio ios::sync_with_stdio(0) cin.tie(0); cout.tie(0)
#define pb push_back
map <int, int> b;

int32_t main()
{
    int t , ans = 0;
    cin >> t;
    vector<int> a;
    vector<int> v[t];
    for (int tt = 0; tt < t; tt++)
    {
        int x;
        cin >> x;
        for (int j = 0; j < x; j++)
        {
            int y;
            cin >> y;
            v[tt].push_back(y);
            a.push_back(y);
        }
    }
    sort(a.begin(), a.end());
    for (int i = 0; i < a.size(); i++)
        b[a[i]] = i;
    for (int i = 0; i < t; i++)
        for (int j = 0; j < v[i].size() - 1; j++)
            if (b[v[i][j + 1]] - b[v[i][j]] != 1)
                ans++;
    cout << ans << " " << t - 1 + ans << endl;
}