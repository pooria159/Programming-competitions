#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"
#define file_io freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout)
#define fastio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define pb push_back
#define PI 3.14159
#define pii pair<int, int>
int mod = pow(10,9)+7;
int maxn = pow(10,5)+7;
int minx  = -1*pow(10,5)+7;

int32_t main()
{
    int n , ans=0;
    cin >> n;
    int a[n];
    for (int i = 0; i < n ; i++)cin >> a[i];
    for (int j = 2; j < n ; j++){
        a[j] = min(a[j]+a[j-1], a[j]+a[j-2]);
    }
    ans = min(a[n-1], a[n-2]);
    cout << ans << endl;  
}