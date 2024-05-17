#include <bits/stdc++.h>
using namespace std;

#define int long long 
#define endl "\n"
#define file_io freopen("input.txt","r",stdin);freopen("output.txt","w",stdout)
#define fastio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define pb push_back
#define PI 3.14159
#define pii pair<int,int>
#define max INT32_MAX
map<int, int> mp;

int32_t main()
{
    fastio;
    int t;
    cin >> t;
    while(t--)
    {
        string s1 , s2;
        cin >> s1;
        cin >> s2;
        if(s1[0] == s2[0]){
            cout<<"YES\n"<<s1[0] << "*\n" ; 
            continue ; 
        }
        if(s1[s1.size() - 1] == s2[s2.size() - 1]){
            cout<<"YES\n"<<"*" << s1[s1.size() - 1] << "\n" ; 
            continue ; 
        }
        int ff = 0 ; 
        for(int i = 1 ; i < s1.size() ; i ++ ){
            for(int j = 1 ; j < s2.size() ; j ++ ){
                if(s1[i] == s2[j] && s1[i-1] == s2[j-1]){
                    cout<<"YES\n"<<"*"<<s1[i-1]<<s1[i]<<"*\n" ; 
                    ff = 1 ; 
                    break ; 
                }
            }
            if(ff) break ; 
        }
        if(ff == 0){
            cout<<"NO\n" ; 
        }
    }
}