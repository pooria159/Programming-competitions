#include <bits/stdc++.h>
using namespace std;

#define int long long 
#define endl "\n"
#define file_io freopen("input.txt","r",stdin);freopen("output.txt","w",stdout)
#define fastio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define pb push_back
#define PI 3.14159
#define pii pair<int,int>
map<int, int> mp;


int32_t main()
{
    int n;
    cin >> n;
    string str[n];
    for(int x = 0 ; x < n ; x++)cin >> str[x];
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < n ; j++){
            bool mark = true;
            bool mark2 = true;
            bool mark3 = true;
            bool mark4 = true;
            if(str[i][j] == '.'){
                if(i > 0 && j > 1){
                    (str[i-1][j-2]=='A') ? mark = false : true;
                }
                if(i > 1 && j > 0){
                    (str[i-2][j-1]=='A') ? mark2 = false : true;
                }
                if(i > 0 && j+2 < n){
                    (str[i-1][j+2]=='A') ? mark3 = false : true;
                }
                if(i > 1 && j+1 < n){
                    (str[i-2][j+1]=='A') ? mark4 = false : true;
                }
                (mark == true && mark2 == true && mark3 == true && mark4==true) ? str[i][j]='A' : str[i][j]='.';
            }
        }
    }
    for(int h=0 ; h < n ; h++)
        cout<< str[h] << endl;
}