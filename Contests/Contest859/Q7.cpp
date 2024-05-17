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
    fastio;
    int t;
    cin >> t;
    while(t--){
        int l;
        cin >> l;
        vector<int> arr(l);
        for (int j = 0; j < l; j++) {
            cin >> arr[j];
        }
        if (l == 1) {
            if (arr[0] == 1) {
                cout << "YES" << endl;
            }
            else {
                cout << "NO" << endl;
            }
            continue;
        }
        sort(arr.begin(), arr.end());
        int c = 1;
        int p = 1;
        int temp = 1;
        bool mark = true;
        while (c < l) {
            if (arr[c] > temp) {
                mark = false;
                break;
            }
            temp += arr[c];
            c++;
        }
        cout << (mark ? "YES" : "NO") << endl;
    }
}
