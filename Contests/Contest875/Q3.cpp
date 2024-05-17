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
vector<int> present;
int edg;
int rightpos[numeric];
int left[numeric];
stack<int> stk;
int make_pow(int n, int y, int mod) { return (!y ? 1 : (y & 1 ? n * make_pow((n * n) % mod, y / 2, mod) % mod : make_pow((n * n) % mod, y / 2, mod) % mod)); }


void check(int root, vector<vector<int>>& adj, vector<int>& grahp_is_create, vector<int>& arr){
    stack<int> tmp;tmp.push(root);
    vector<bool> flag(adj.size(), false);
    int x, y;
    while(!tmp.empty()) {
        x = tmp.top();flag[x] = true;
        bool check_is_good = false;
        for(const auto& y : adj[x]) {
            if(!flag[y]) {
                tmp.push(y);
                (arr[x] > arr[y]) ? grahp_is_create[y] = grahp_is_create[x] + 1 : grahp_is_create[y] = grahp_is_create[x];
                check_is_good = true;break;
            }
        }
        if (!check_is_good) tmp.pop();
    }
}

vector<int> result(int root, vector<vector<int>>& adj) {
    stack<int> buff;buff.push(root);
    vector<bool> flag(adj.size(), false);
    vector<int> parent(adj.size(), -1);
    int x, y;
    while (!buff.empty()){
        x = buff.top();flag[x] = true;
        bool check_is_good = false;
        for (const auto& y : adj[x]) {
            if (!flag[y]){
                buff.push(y);parent[y] = x;
                check_is_good = true;break;
            }
        }
        if (!check_is_good) buff.pop();
    }
    return parent;
}

int32_t main() {
    fastio;
    int t, n, u, v;cin >> t;
    for(int x = 0; x < t; ++x){
        cin >> n;
        vector<vector<int>> adj(n);vector<int> arr(n);vector<pair<int, int>> inisex;
        for(int y = 0; y < n - 1; ++y) {
            cin >> u >> v;
            --u;--v;
            adj[u].push_back(v);
            adj[v].push_back(u);
            inisex.emplace_back(u, v);
        }
        vector<int> parent = result(0, adj);
        for (int i = 0; i < n - 1; i++) {
            u = inisex[i].ff;
            v = inisex[i].ss;
            (u == parent[v]) ? arr[v] = i :arr[u] = i;
        }
        vector<int> grahp_is_create(n);
        check(0, adj, grahp_is_create, arr);
        cout << *max_element(grahp_is_create.begin(), grahp_is_create.end()) + 1 << endl;
    }
}