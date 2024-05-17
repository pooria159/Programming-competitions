#include <bits/stdc++.h>
using namespace std;
#define int long long
#define uint unsigned long long
#define endl '\n'
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
#define ABS(n) ((n) < 0 ? -(n) : (n))
#define SORT(v) sort(v.begin(), v.end())
#define REV(v) reverse(v.begin(), v.end())
#define SQR(a) ((a) * (a))
#define FOR(i, n, p) for (int i = n; i < p; i++)
#define ROF(i, n, p) for (int i = p - 1; i > n; i--)
#define FOOR(i, n, p) for (int i = n; i < p; i += 2)
#define maxres *max_element
int MOD = 1e9 + 7;
const int numeric = 100005;

const int maxn = 5e3 + 5 ; 
int n , a[maxn] , mp[maxn][maxn] , ms[maxn][maxn] , ans ; 


int32_t main()
{
    int t;
    cin >> t;
    while (t--)
    {
      cin>>n ; 
      for(int i = 1 ; i <= n ; i ++ ){
        cin>>a[i] ; 
      }
      int mx = 0 ; 
      for(int i = 1 ; i <= n ; i ++ ){
        mx = a[i] ; 
        mp[i][i] = 1 ; 
        for(int j = i + 1 ; j <= n ; j ++ ){
            if(a[j] > mx){
                
            }
        }
      }  
    }
    
}