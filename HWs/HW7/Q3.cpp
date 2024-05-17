#include <bits/stdc++.h>
#include <bitset>
using namespace std;
#define int long long
#define uint unsigned long long
#define endl '\n'
#define file_io freopen("input.txt", "r", stdin);freopen("output.txt", "w", stdout)
#define fastio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define ff first
#define ss second
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
#define maxres *max_element
int mod = 1e9 + 7;
const int numeric = 100005;
vector<int> graph[numeric];
bitset<numeric> ch;
int make_pow(int n , int y , int mod){return(!y ? 1 : (y & 1 ? n * make_pow((n * n) % mod , y/2 , mod) % mod : make_pow((n * n) % mod , y/2 , mod) % mod ));}


int32_t main()
{
    fastio;
    int n , m;
    cin >> n >> m;
    FOR(i,0,m){
        int u, v;
        cin >> u >> v;
        graph[u].pb(v);
        graph[v].pb(u);
    }
    int q; 
    cin >> q;
    FOR(i,0,q){
        int u,v;
        cin >> u >> v;
        ch.reset();
        for(int h : graph[u])
            ch.set(h);
        if (ch[v]) {
            cout << "NO" << endl;
            continue;
        }
        ch.reset();
        for (int h : graph[v])
            ch.set(h);
        if (ch[u]) {
            cout << "NO" << endl;
            continue;
        }
        cout << "YES" << endl;
    }
}

