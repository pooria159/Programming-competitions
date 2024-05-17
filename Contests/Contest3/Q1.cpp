#include <bits/stdc++.h>
using namespace std;

#define int long long 
#define endl "\n"
#define file_io freopen("input.txt","r",stdin);freopen("output.txt","w",stdout)
#define fastio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define pb push_back
#define pop pop_back
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
        int n  , m;
        cin >> n >> m;
        int x= n;
        bool mark[m] = {false};
        fill(mark, mark );
        vector <int> a;
        vector <int> b;
        int ans[n];
        for (int i = 0; i < m ; i++){cin >> a[i];}
        for (int j = 0; j < m ; j++) b[j] = j;
        for (int h = 0; h < m ; h++){
            if(mark[a[h]]==false){
                b.insert(b.begin() , a[h]);
                b.pop();
                ans[x]++;
                x--;
            }
            else if(mark[a[h]]==true)
            {
                b.insert(b.begin() ,a[h]);
                b.erase(b.begin() + h);
                ans[]
            }
        }
        for (int i = 0; i < n ; i++)
        {
            if(mp[i] = 0){
                cout << -1 << endl;
            }
            else{
                cout << mp[i] << endl;
            }
        }
    }
}