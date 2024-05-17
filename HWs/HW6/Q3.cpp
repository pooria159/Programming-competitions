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
map<int,int> mp = {{1,1},{2,1},{3,2},{4,9}};
int mod = 1e9 + 7;
const int numeric = 10000;
int dp[numeric][numeric];
int make_pow(int x , int y , int mod){return(!y ? 1 : (y & 1 ? x * make_pow((x * x) % mod , y/2 , mod) % mod : make_pow((x * x) % mod , y/2 , mod) % mod ));}
int result(int n , int k){
    int temp = 1;
    if(k == 1){return temp;}
    else{FOR(i,1,k+1){
        temp = temp * (n-i+1);
        temp/= i;
    }temp = temp * mp[k]; return temp;}
}


int32_t main(){
    int n,k,sum=0;
    cin >> n >> k;
    FOR(i,1,k+1){sum = sum + result(n,i);}
    cout << sum << endl;
}


