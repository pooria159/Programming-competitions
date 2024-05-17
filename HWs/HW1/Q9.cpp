#include <bits/stdc++.h>
using namespace std;

#define int long long 
#define endl "\n"
// #define file_io freopen("input.txt","r",stdin);freopen("output.txt","w",stdout)
#define fastio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)

int32_t main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int j = 0; j < n ; j++)
    {
        if(a[j] <= 3)
        {
            for (int h = 0; h < a[j]; h++)
            {
                cout << "*";
            }
            cout << endl;
        }
        else
        {
            cout << "*" << endl;
        }
    }
}