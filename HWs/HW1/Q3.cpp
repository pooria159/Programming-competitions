#include <bits/stdc++.h>
using namespace std;

#define int long long 
#define endl "\n"
// #define file_io freopen("input.txt","r",stdin);freopen("output.txt","w",stdout)
#define fastio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)

int32_t main()
{
    int n , x, k;
    cin >> n >> x >> k;
    string line[n];
    for (int i = 0; i < n; i++){
        cin >> line[i];
    }
    int a = ((x+k)%n-1+n)%n;
    cout << line[a] << endl;
}