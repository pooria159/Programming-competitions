#include <bits/stdc++.h>
using namespace std;

#define int long long 
// #define endl "\n"
// #define file_io freopen("input.txt","r",stdin);freopen("output.txt","w",stdout)
#define fastio ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr)

int32_t main()
{
    fastio;
    // file_io;
    int t;
    cin>>t;
    while(t--)
    {
        int n ,mark = 1;
        cin>>n;
        int a[n];
        for (int i = 0; i < n ; i++){cin>>a[i];}
        for (int j = 0; j < n; j+=2){
            if(a[j] % 2 != a[0] % 2){
                mark = 0;
            }
        }
        for (int h = 1; h < n; h+=2){
            if(a[h] % 2 != a[1] % 2){
                mark = 0;
            }
        }
        if(mark == 1){
            cout<<"YES"<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }
    }
}


