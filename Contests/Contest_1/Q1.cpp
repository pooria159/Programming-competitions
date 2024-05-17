#include <bits/stdc++.h>
using namespace std;

#define int long long 
#define endl "\n"
// #define file_io freopen("input.txt","r",stdin);freopen("output.txt","w",stdout)
#define fastio ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr)

int32_t main()
{
    fastio;
    int t;
    cin >> t;
    for (int i = 0; i < t; i++){
        int n , m , newlen = 0 , ans =0;
        bool flag = true;
        cin >> n >> m;
        newlen = m +n;
        string a , b;
        cin >> a >> b;
        string c= a;
        for(int i = m -1 ; i> -1 ; i--){
            c.push_back(b[i]);
        }
        for(int j = 0 ; j < newlen ; j++){
            if(c[j] == c[j+1])
            {
                ans++;
            }
        }
        if(ans==1 || ans==0)
        {
            cout << "YES" << endl;
        }
        else{
            cout << "NO" << endl;
        }
    }
}