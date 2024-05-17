#include <bits/stdc++.h>
using namespace std;
#define int long long
#define uint unsigned long long
#define endl "\n"
#define file_io                       \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout)
#define fastio               \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0)
#define ff first
#define ss second
#define pb push_back
#define mk make_pair
#define pii pair<int, int>
#define ABS(x) ((x) < 0 ? -(x) : (x))
#define SORT(v) sort(v.begin(), v.end())
#define REV(v) reverse(v.begin(), v.end())
#define SQR(a) ((a) * (a))
#define FOR(i, x, n) for (int i = x; i < n; i++)
#define ROF(i, x, n) for (int i = n - 1; i >= x; i--)
int mod = 1e9 + 7;



int32_t main(){
    fastio;
    int n;
    cin>>n;
    int a[n+100];
    FOR(i,1,n+1)cin>>a[i];
    int t;
    cin>>t;
    while(t--){
        int s , k;
        cin>>s>>k;
        int ans=0;
        FOR(i,0,(n-s)/k+1)ans+=a[s+(i*k)];
        cout<<ans<<endl;
    }
}