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
const int numeric = 2e5 + 9;
int parent[numeric];
bool visited[numeric];
vector<int> present;
int edg;
int dist[numeric];
vector<int> pos[10];
stack<int> stk;
int make_pow(int n , int y , int mod){return(!y ? 1 : (y & 1 ? n * make_pow((n * n) % mod , y/2 , mod) % mod : make_pow((n * n) % mod , y/2 , mod) % mod ));}


int32_t main() {
    int n;
    string s;
    cin >> n >> s;
    FOR(i,0,n){pos[s[i] - '0'].pb(i);dist[i] = -1;}
    queue<int> q;
    q.push(0);
    dist[0] = 0;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        if (u > 0 && dist[u - 1] == -1) {
            dist[u - 1] = dist[u] + 1;
            q.push(u - 1);
        }
        if (u < n - 1 && dist[u + 1] == -1) {
            dist[u + 1] = dist[u] + 1;
            q.push(u + 1);
        }
        for (int v : pos[s[u] - '0']) {
            if (dist[v] == -1) {
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
        pos[s[u] - '0'].clear();
    }
    cout << dist[n - 1] << endl;
}
