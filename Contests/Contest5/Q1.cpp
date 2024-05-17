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
        int n , mark =0; 
        cin >> n;
        string my_str;
        cin >> my_str;
        bool temp = true;
        if(my_str[mark] == 'm' || my_str[mark] == 'M'){
            while(my_str[mark] == 'm' || my_str[mark] == 'M'){
                mark ++;
            }
        }
        else
            temp = false;
        if (my_str[mark] == 'e' || my_str[mark] == 'E'){
            while (my_str[mark] == 'e' || my_str[mark] == 'E'){
                mark ++;
            }
        }
        else
            temp = false;
        if (my_str[mark] == 'o' || my_str[mark] == 'O'){
            while (my_str[mark] == 'o' || my_str[mark] == 'O'){
                mark ++;
            }
        }
        
        else
            temp = false;
        if (my_str[mark] == 'w' || my_str[mark] == 'W'){
            while (my_str[mark] == 'w' || my_str[mark] == 'W'){
                mark ++;
            }
        } 
        else
            temp = false;
        mark == n && temp == true ? cout << "Yes" << endl : cout << "No" << endl;
    }

}