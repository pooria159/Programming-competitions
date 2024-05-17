#include <bits/stdc++.h>
using namespace std;

#define int long long 
#define endl "\n"
// #define file_io freopen("input.txt","r",stdin);freopen("output.txt","w",stdout)
#define fastio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define pb push_back


int32_t main()
{
    fastio;
    int n , b = 0;
    cin >> n;
    int sample = pow(10,9)+7;
    int a[n+2];
    a[0] = 1;
    a[1] = 1;
    for (int i =2 ; i < n ; i++)
    {
        a[i] = a[i-1] + a[i-2];
        b+= a[i];
    }
    cout << sample << endl;
    cout << b << endl;
    cout << b%sample << endl;
}