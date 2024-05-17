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
        int n;
        bool mark = true;
        cin >> n;
        string s = "FBFFBFFBFBFFBFFBF";
        string str;
        cin >> str;
        size_t ans = s.find(str);
        ans != string::npos ? cout << "Yes" << endl : cout << "No" << endl;
    }
}