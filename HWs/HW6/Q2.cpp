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
#define ABS(x) ((x) < 0 ? -(x) : (x))
#define SORT(v) sort(v.begin(), v.end())
#define REV(v) reverse(v.begin(), v.end())
#define SQR(a) ((a) * (a))
#define FOR(i, x, p) for (int i = x; i < p; i++)
#define ROF(i, x, p) for (int i = p - 1; i > x; i--)
#define FOOR(i, x , p) for (int i = x ; i < p; i+=2)
#define maxres *max_element
int mod = 1e9 + 7;
int make_pow(int x , int y , int mod){return(!y ? 1 : (y & 1 ? x * make_pow((x * x) % mod , y/2 , mod) % mod : make_pow((x * x) % mod , y/2 , mod) % mod ));}



int32_t main(){
    fastio;
    int n,m;
    cin>>n>>m;
    vector<int>f(2*m+n+5);
    vector<int>inv(2*m+n+5);
    f[0]=f[1]=inv[0]=inv[1]=1;
    for(int i=1;i<f.size();i++){
       f[i]=(f[i-1]*i)%mod;
       inv[i]=make_pow(f[i],mod-2 , mod);
    }
    int ans=((f[2*m+n-1]*inv[n-1])%mod * inv[2*m])%mod;
    cout<<ans<<endl;
}

    
