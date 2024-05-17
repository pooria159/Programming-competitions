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


int32_t main() {
    fastio;
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<int> a(n), b(n);
        for(int i=0; i<n; i++) {
            cin >> a[i];
        }
        for(int i=0; i<n; i++) {
            cin >> b[i];
        }
        bool pos = true;
        for(int i=0; i<n-1; i++){
            if(a[i] > a[n-1]){
                if(a[i] > b[n-1] || b[i] > a[n-1]){
                    pos = false;
                    break;
                }
            }
        }
        if(pos){
            for(int i=0; i<n-1; i++) {
                if(b[i] > b[n-1]) {
                    if(b[i] > a[n-1] || a[i] > b[n-1]) {
                        pos = false;
                        break;
                    }
                }
            }
        }
        cout << (pos ? "Yes" : "No") << endl;
    }
    return 0;
}
