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
    int t;
    cin >> t;
    while (t--)
    {
        int n, flag = 0;
        cin >> n;
        string str;
        string s[n];
        vector<string> v;
        for(int i = 0; i < 2*n - 2 ; i++){
            cin >> s[i];
            if(s[i].length() == n- 1){
                v.pb(s[i]);
            }
        }
        for(int j=0 ;  j < v.size() ; j++)
        {
            for(int i = 0 ; i < n-1 ;i++)
            {
                if(v[i]
            }
        }
        for (int i = 0; i < n; i++){
            if(str[i] != str[n-i-1]){
                flag = 1;
                break;
            }
        }
        (flag) ? cout << "No" << endl : cout << "Yes" << endl;
        
    }
    
}


