#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"
#define file_io freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout)
#define fastio ios::sync_with_stdio(0)cin.tie(0);cout.tie(0)
#define pb push_back
#define PI 3.14159
#define pii pair<int, int>
int mod = pow(10,9)+7;



int make_pow(int x , int y , int mod)
{
    return(!y ? 1 : (y & 1 ? x * make_pow((x * x) % mod , y/2 , mod) % mod : make_pow((x * x) % mod , y/2 , mod) % mod )) ; 
}

int32_t main()
{
    int n, k , ans = 1, res = 1;
    cin >> n >> k;
    for (int i =  n ; i > n - k ; i--){
        ans*=i;
        ans %= mod;
    }
    for (int i = k ; i > 0 ; i--){
        res*=i;
        res %= mod;
    }
    res = make_pow(res, mod - 2 , mod) % mod;
    cout << (ans * res) % mod;

}
