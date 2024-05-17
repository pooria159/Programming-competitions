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
#define FOOR(i, n, p) for (int i = n; i < p; i += 2)
#define maxres *max_element
int mod = 1e9 + 7;
const int numeric = 2e5 + 500;
int parent[numeric], tmp[numeric];
bool visited[numeric];
vector<int> present;
int edg;
int rightpos[numeric];
int left[numeric];
stack<int> stk;
int make_pow(int n, int y, int mod) { return (!y ? 1 : (y & 1 ? n * make_pow((n * n) % mod, y / 2, mod) % mod : make_pow((n * n) % mod, y / 2, mod) % mod)); }

int32_t main(){
    fastio;
    int t;
    cin >> t;
    for (int i = 0; i < t; i++){
        int n;
        cin >> n;
        vector<int> ans1(n);
        vector<int> ans2(n);
        for (int i = 0; i < n; i++) cin >> ans1[i];
        for (int i = 0; i < n; i++) cin >> ans2[i];
        vector<int> larr(2 * n + 1, 0);
        vector<int> sarr(2 * n + 1, 0);
        int res = -1 , buff=0;
        for (int i = 0; i < n; i++){
            if (ans1[i] != ans1[i - 1] || res == -1){
                res = 1;larr[ans1[i]] = max(res, larr[ans1[i]]);
            }
            else{
                res++;larr[ans1[i]] = max(res, larr[ans1[i]]);
            }
        }
        res = -1;
        for (int i = 0; i < n; i++){
            if (ans2[i] != ans2[i - 1] || res == -1){
                res = 1;sarr[ans2[i]] = max(res, sarr[ans2[i]]);
            }
            else{
                res++;sarr[ans2[i]] = max(res, sarr[ans2[i]]);
            }
        }
        for (int i = 1; i <= 2 * n; i++) buff = max(buff, larr[i] + sarr[i]);
        cout << buff << endl;
    }
}
