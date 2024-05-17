#include <bits/stdc++.h>
using namespace std;

#define int long long 
// #define endl "\n"
// #define file_io freopen("input.txt","r",stdin);freopen("output.txt","w",stdout)
// #define fastio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)

int32_t main()
{
    // fastio;
    // file_io;
    int t;
    cin>>t;
    for (int i = 0; i < t; i++)
    {
        int a;
        cin>>a;
        if(a < 1400){
            cout<< "Division 4" << endl;
        }
        else if(a < 1600){
            cout<< "Division 3" << endl;
        }
        else if(a < 1900){
            cout<< "Division 2" << endl;
        }
        else{
            cout<< "Division 1" << endl;
        }
    }   
}