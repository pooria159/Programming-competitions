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

int32_t main()
{
    fastio;
    int n;
    cin >> n;
    int a[n];
    for(int i = 0; i < n; i++) cin >> a[i];
    sort(a , a + n);
    int blue = 0 , red = 0 , ans = 1; 
    for(int i=0 ; i < n ; i++){
        if(a[i]!=a[i-1] && a[i]!=a[i+1]){
            a[i] = 0;
            if(ans%2==1) blue++;
            ans++;
        }
    }
    for(int i=0 ; i < n ; i++) if(a[i]!=a[i-1] && a[i]!=0) red++;
    cout << blue + red << endl;
}