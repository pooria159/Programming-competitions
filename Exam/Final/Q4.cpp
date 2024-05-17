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
const int maxn = 1e6 + 7;
int parent[maxn];
int tmp[maxn];
int res[maxn];
pair<pii , pii> buff[maxn];

int find(int x){
    if(parent[x]==x) return x;
    return parent[x] = find(parent[x]);
}


void unite(int x, int y)
{
    x = find(x);
    y = find(y);
    if(x==y) return;
    if(x!=y){
        if(tmp[x] < tmp[y]) swap(x,y);
        parent[y] = x;
        tmp[x] += tmp[y];
    }
}


int32_t main(){
    fastio;
    int n;
    cin >> n;
    for(int i = 0; i < n-1; i++){
        int a , b , c;
        cin >> buff[i].ss.ff >> buff[i].ss.ss >> buff[i].ff.ff;buff[i].ff.ss = i;
    }
    sort(buff , buff +n);
    for(int i = 0; i < n ; i++){
        parent[i] = i; tmp[i] = 1;
    }
    for(int i = 0; i < n ; i++){
        int x,y,z,h;
        x= buff[i].ss.ff; y =buff[i].ss.ss;
        z = buff[i].ff.ff; h = buff[i].ff.ss;
        res[h] = tmp[find(x)] * tmp[find(y)];
        unite(x,y);
    }
    for(int i=0 ; i < n - 1 ; i++) cout << 2 * res[i] << " ";
    cout << endl;
    return 0;
}