#include <bits/stdc++.h>
using namespace std;
#define int long long
#define uint unsigned long long
#define endl '\n'
#define file_io freopen("input.txt", "r", stdin);freopen("output.txt", "w", stdout)
#define fastio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define pb push_back
#define mk make_pair
#define pii pair<int, int>
#define ABS(n) ((n) < 0 ? -(n) : (n))
#define SORT(v) sort(v.begin(), v.end())
#define REV(v) reverse(v.begin(), v.end())
#define SQR(a) ((a) * (a))
#define FOR(i, n, p) for (int i = n; i < p; i++)
#define ROF(i, n, p) for (int i = p - 1; i > n; i--)
#define FOOR(i, n , p) for (int i = n ; i < p; i+=2)


int32_t main()
{
    fastio;
    int x,y;
    cin >> x >> y;
    int a[x][y];
    int cnt = 1;
    for (int i = 0; i < x; i++) {
        if (i % 2 == 0) {
            for (int j = 0; j < y; j++) {
                a[i][j] = cnt++;
            }
        } else {
            for (int j = y-1; j >= 0; j--) {
                a[i][j] = cnt++;
            }
        }
    }
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
}
