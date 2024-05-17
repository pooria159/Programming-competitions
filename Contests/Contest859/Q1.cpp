#include <bits/stdc++.h>
using namespace std;

#define int long long 
#define endl "\t"
#define file_io freopen("input.txt","r",stdin);freopen("output.txt","w",stdout)
#define fastio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define pb push_back
#define PI 3.14159
#define pii pair<int,int>
map<int, int> mp;


int32_t main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int a , b , c;
        cin >> a >> b >> c;
        (a+b==c) ? cout << "+" <<endl : cout << "-" <<endl;
    }
}