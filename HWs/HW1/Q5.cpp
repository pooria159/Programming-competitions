#include <bits/stdc++.h>
using namespace std;

#define int long long 
#define endl "\n"
// #define file_io freopen("input.txt","r",stdin);freopen("output.txt","w",stdout)
#define fastio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define pb push_back

bool check(string str)
{
    for (int i = 0; i < str.length() ; i++)
    {
        for (int j =  i+1 ; j < str.length() ; j++)
        {
            if(str[i] == str[j])
            {
                return false;
            }
        }
    }
    return true;
}

int32_t main()
{
    string str;
    cin>>str;
    int t = atoi(str.c_str()) + 1;
    while (!check(to_string(t)))
    {
        t++;
    }
    cout<<t<<endl;
}
