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
const int numeric = 100005;
vector<int> buff[numeric];
int a[numeric];
set<int> father;
int make_pow(int n , int y , int mod){return(!y ? 1 : (y & 1 ? n * make_pow((n * n) % mod , y/2 , mod) % mod : make_pow((n * n) % mod , y/2 , mod) % mod ));}
void add_element(int x , int y){buff[x].pb(y); buff[y].pb(x);}
void dfs(int n){a[n] = 1; for(auto i : buff[n]) if(a[i] == 0) dfs(i);}

int32_t main(){
    fastio;
    int n , m , u , v,res=0;;
    cin >> n >> m;
    FOR(i,0,m){
        cin >> u >> v;
        u--; v--;
        add_element(u,v);
    }FOR(i,0,n){
        if(a[i]==0){
            if(buff[i].size()!= 0){
                father.insert(i);
            }dfs(i);
        }
    }
    FOR(i,0,n){
        if(buff[i].size() % 2 != 0){
            res++;
        }
    }
    if(res <= 2 && father.size() < 2)
    {
        cout << "YES" << endl;
    }else{
        cout << "NO" << endl;
    }
}


