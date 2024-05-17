#include <bits/stdc++.h>
using namespace std;

#define int long long 
#define endl "\n"
// #define file_io freopen("input.txt","r",stdin);freopen("output.txt","w",stdout)
#define fastio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)

int32_t main()
{
    int t , m = 0;
    cin>>t;
    int a[t];
    for(int i=0;i<t;i++){
        cin>>a[i];
        m+=a[i];
    }
    int max = a[0] , min = 0;
    for (int j = 0; j < t ; j++){
        if(a[j] < max){
            max = a[j];
        }
    }
    min = m - (t-1)*100;
    if(min > 0){
        cout<<min<<" "<<max<<endl;
    }
    else{
        cout<<0<<" "<<max<<endl;
    }
}