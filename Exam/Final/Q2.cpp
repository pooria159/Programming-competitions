#include <bits/stdc++.h>
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
int make_pow(int n , int y , int mod){return(!y ? 1 : (y & 1 ? n * make_pow((n * n) % mod , y/2 , mod) % mod : make_pow((n * n) % mod , y/2 , mod) % mod ));}
const int maxn = 1e5 + 7;
vector<int> a[maxn];
int visited[maxn];
int parent[maxn];
int res = 0;

int dfs(int u){
    visited[u] = 1;
    int ans = 1;
    for(int i = 0; i < a[u].size() ; i++){
        int check = a[u][i];
        if(check==parent[u]) continue;
        if(!visited[check]){
            parent[check]= u;
            ans = ans + dfs(check);
        }
    }
    if(ans%2==0) res++;
    return ans;
}

int32_t main(){
    fastio;
    int n;
    cin >> n;
    for(int i=1 ; i<= n-1 ; i++){
        int u , v;
        cin >> u >> v;
        a[u].push_back(v);
        a[v].push_back(u);
    }
    if(n%2==1){
        cout << "-1" << endl;
        return 0;
    }
    for(int j=1 ; j <= n ; j++){
        if(visited[j]==0){
            dfs(j);
        }
    }
    cout << res - 1 << endl;
}