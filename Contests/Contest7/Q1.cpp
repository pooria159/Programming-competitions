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
    fastio;
    int t;
    cin >> t;
    while (t--){
        int n;
        cin >> n;
        vector<int> a(n);
        vector<int> max_likes(n+1);
        vector<int> min_likes(n+1);
        int curr_likes = 0;
        for (int i = 0; i < n; i++){
            cin >> a[i];
            curr_likes += (a[i] > 0) ? 1 : -1;
            max_likes[i] = max(max_likes[i], curr_likes);
            min_likes[i] = min(min_likes[i], curr_likes);
        }
        for (int i = 0; i < n; i++){
            cout << max_likes[i] << " ";
        }
        cout << endl;
        for (int i =0 ; i < n; i++){
            cout << min_likes[i] << " ";
        }
        cout << endl;
    }
    
}



