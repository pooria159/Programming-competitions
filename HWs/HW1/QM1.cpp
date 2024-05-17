
#include <bits/stdc++.h>
using namespace std;

#define int long long 
#define endl "\n"
// #define file_io freopen("input.txt","r",stdin);freopen("output.txt","w",stdout)
#define fastio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define pb push_back

bool check_string(char c , string s)
{
    for (int i = 0; i < s.length(); i++)
    {
        if (c == s[i])
        {
            return true;
        }
    }
    return false;
}

int32_t main()
{
    fastio;
    int t;
    cin>>t;
    for (int i = 0; i < t ; i++){
        string f , m , b;
        cin >> f >> m >> b;
        int len_b = b.length() , ans = 1;
        for (int j = 0; j < len_b ; j++)
            if(b[j] != '-' && b[j] != 'O')
                check_string(b[j],f)==false && check_string(b[j],m)==false ? ans = 0 : 1;
        (ans==1) ? cout << "valid" << endl : cout << "invalid" << endl;
    }
}
