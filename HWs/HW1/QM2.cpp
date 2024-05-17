#include <bits/stdc++.h>
using namespace std;

#define int long long 
#define endl "\n"
// #define file_io freopen("input.txt","r",stdin);freopen("output.txt","w",stdout)
#define fastio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)

int32_t main()
{
    int t , plus = 0 , minus = 0 , ans = 0;
    cin>>t;
    int a[t];
    for(int i=0;i<t;i++){
        cin>>a[i];
        if(a[i] >= 0){
            plus++;
        }
        else{
            minus++;
        }
    }
    ans = (plus*minus) + (minus * (minus-1));
    cout<<ans<<endl;
}