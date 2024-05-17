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
const int numeric = 10000;
int dp[numeric][numeric];
int make_pow(int n , int y , int mod){return(!y ? 1 : (y & 1 ? n * make_pow((n * n) % mod , y/2 , mod) % mod : make_pow((n * n) % mod , y/2 , mod) % mod ));}

const int N=2e5+9;
vector<pair<int,int>>v[N];
int dist[N],change[N],total=0;
void dfs(int n,int cnt,int d,int par)
{
    change[n]=cnt;
    dist[n]=d;
    for (auto child:v[n])
    {
        if (child.first==par)
            continue;
        total+=child.second;
        dfs(child.first,cnt+child.second,d+1,n);
    }
}


int32_t main(){
    fastio;
    int n;
    cin>>n;
    for (int i=1;i<n;i++){
        int l,r;
        cin>>l>>r;
        v[l].pb({r,0});
        v[r].pb({l,1});
    }
    dfs(1,0,0,-1);
    int mn=1e9;
    for (int i=1;i<=n;i++)
    {
        mn=min(mn,total-change[i]+dist[i]-change[i]);
    }
    cout<<mn<<endl;
    for (int i=1;i<=n;i++)
    {
        if (total-change[i]+dist[i]-change[i]==mn)
            cout<<i<<" ";
    }
}
