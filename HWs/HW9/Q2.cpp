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
const int numeric = 2e5 + 500;
int parent[numeric] , tmp[numeric];
bool visited[numeric];
vector<int> present;
int edg;
int rightpos[numeric];
int left[numeric];
stack<int> stk;
int make_pow(int n , int y , int mod){return(!y ? 1 : (y & 1 ? n * make_pow((n * n) % mod , y/2 , mod) % mod : make_pow((n * n) % mod , y/2 , mod) % mod ));}

int find_dis(int a[] , int b){
    if(a[b]==b){
        return b;
    }
    return a[b] = find_dis(a,a[b]);
}

int find(int x) {
    if (parent[x] == x) return x;
    return parent[x] = find(parent[x]);
}

void unite(int x, int y) {
    x = find(x), y = find(y);
    if( x==y ) return;
    if (x != y){
        if (tmp[x] < tmp[y]) swap(x, y);
        parent[y] = x;
        tmp[x] += tmp[y];
    }
}

int32_t main(){
    fastio;
    int n, q;
    cin >> n >> q;
    for(int i = 1; i <= n; i++){
        parent[i] = i;
        rightpos[i] = i;
        tmp[i] = 1;
    }
    for(int i = 1; i <= q; i++){
        int op, x, y;
        cin >> op >> x >> y;
        if (op == 1) {
            unite(x, y);
        } 
        else if(op == 2){
            for(;x < y ; x = find_dis(rightpos,x)){
                rightpos[x] = x+1;
                unite(x,rightpos[x]);
            }
        } 
        else{find(x) == find(y) ? cout << "YES" << endl : cout << "NO" << endl;}
    }
}