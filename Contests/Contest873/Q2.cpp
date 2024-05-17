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

int32_t main() {
    fastio;
    int t,ans=0;
    cin >> t;
    FOR(i,0,t){
        int n;
        cin >> n;
        vector<int> p(n+1);
        vector<int> h(n);
        FOR(k,1,n+1)
        {
            cin >> p[k];
        }
        FOR(j,1,n+1){
            h[p[j]-1] = ABS(p[j]-j);
        }
        FOR(a,0,h.size()){
            if(h[a] != 0){
                ans = h[a];
                break;
            }
        }
        FOR(b,0,h.size()){
            if(h[b] != 0) ans = __gcd(ans , h[b]);
        } 
        cout << ans << endl;
    }
}