#include <bits/stdc++.h>
using namespace std;

#define int long long 
#define endl "\n"
#define file_io freopen("input.txt","r",stdin);freopen("output.txt","w",stdout)
#define fastio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define pb push_back
#define PI 3.14159
#define pii pair<int,int>
map<int, int> mp;

int calc(int n){
    int x = 0 , y = 0;
    for(int i=1 ; i <= n ; i++){
        y = n/i;
        x = x + ((y*i)*(y+1));
    }
    return x;
}

int32_t main()
{
    int n , ans = 0;
    cin >> n;
    ans = calc(n) / 2;
    cout << ans << endl;
}
