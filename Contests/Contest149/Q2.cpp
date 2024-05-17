#include <bits/stdc++.h>
using namespace std;
#define int long long
#define uint unsigned long long
#define endl '\n'
#define file_io freopen("input.txt", "r", stdin);freopen("output.txt", "w", stdout)
#define fastio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define ff first
#define pb push_back
#define ss second
#define mk make_pair
#define pii pair<int, int>
#define ABS(n) ((n) < 0 ? -(n) : (n))
#define SORT(v) sort(v.begin(), v.end())
#define REV(v) reverse(v.begin(), v.end())
#define SQR(a) ((a) * (a))
#define FOR(i, n, p) for (int i = n; i < p; i++)
#define ROF(i, n, p) for (int i = p - 1; i > n; i--)
#define FOOR(i, n , p) for (int i = n ; i < p; i+=2)
#define maxres *max_element
int mod = 1e9 + 7;
const int numeric = 1e5 + 9;
int parent[numeric];
bool visited[numeric];
vector<int> present;
int edg;
stack<int> stk;
int make_pow(int n , int y , int mod){return(!y ? 1 : (y & 1 ? n * make_pow((n * n) % mod , y/2 , mod) % mod : make_pow((n * n) % mod , y/2 , mod) % mod ));}



int32_t main() {
    fastio;
    int t;
    cin >> t;
    while (t--) {
        int j;
        string s;
        cin >> j >> s;
        int n = 0, mn = 0, mi = 0, cc = 0;
        char cur_v = s[0];
        for (char d : s) {
            if (d == cur_v) {
                cc++;
            } else {
                mi = max(mi, cc);
                cc = 1;
                cur_v = d;
            }
        }
        mi = max(mi, cc);
        cout << mi + 1 << endl;
    }
    return 0;
}
