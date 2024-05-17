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

int32_t main()
{
    int n , ans=0;
    cin >> n;
    vector<int> a;
    for(int x = 0 ; x < n ; x++){
        int b;
        cin >> b;
        a.pb(b);
    }
    for(int y=1 ; y < n ; y++){
        if(a[y-1] > a[y]){
            ans =  ans + (a[y-1]-a[y]);
            a[y] = a[y-1];
        }
    }
    cout << ans << endl;
}