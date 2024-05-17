#include <bits/stdc++.h>
using namespace std;

#define int long long 
#define endl "\n"
// #define file_io freopen("input.txt","r",stdin);freopen("output.txt","w",stdout)
#define fastio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)

int32_t main()
{
    fastio;
    string str;
    cin >> str;
    int len_str =  str.length();
    if(str== "1"){
        cout <<str;
    }
    else if (str == "2"){
        cout <<str;
    }
    else{
        for (int i = len_str -1 ; i > -1 ; i--)
        {
            if(str[i]=='0'){
                str[i] = '9';
            }
            else if (str[i]!='0'){
                int temp = (int)str[i] - 1;
                str[i] = (char)temp;
                break;
            }
        }
        if(str[0]=='0'){
            cout << str.substr(1,len_str) << endl;
        }
        else{
            cout << str << endl;  
        }
    }
}