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
const int numeric = 10000;
int dp[numeric][numeric];
int make_pow(int x , int y , int mod){return(!y ? 1 : (y & 1 ? x * make_pow((x * x) % mod , y/2 , mod) % mod : make_pow((x * x) % mod , y/2 , mod) % mod ));}
int FUNC(int p, int q){
	q=min(q,p-q);
	int res =1 ,tmp = 1;
	FOR(i,0,q){res=(res*(p-i))%mod;}
	FOR(j,2,q+1){tmp=(tmp*j)%mod;}
	tmp = make_pow(tmp, mod-2 , mod);
	return (res*tmp)%mod;
}

int32_t main(){
	fastio;
	int p;
    cin >> p;
	int a[p];
    FOR(i,0,p)cin>>a[i];
	ROF(i,-1,p){FOOR(j,i+1,p){
			FOOR(q,i+1,j+1){
				if(a[i]>a[q]){
					int n = dp[i+1][q-1] , k = dp[q+1][j];
					if(((q-i-1)/2)==0 && ((j-q)/2)==0)dp[i][j]=1;
					else if(((q-i-1)/2)==0 && k)dp[i][j]=(dp[i][j]+(((((j-q)/2)+1)*k)%mod))%mod;
					else if(((j-q)/2)==0 && n)dp[i][j]=(dp[i][j]+(dp[i+1][q-1]))%mod;
					else {dp[i][j]=(dp[i][j]+(((FUNC(((q-i-1)/2)+((j-q)/2)+1,((j-q)/2))*n)%mod)*k)%mod)%mod;}
				}
			}
		}
	}cout << dp[0][p-1] << endl;
}

