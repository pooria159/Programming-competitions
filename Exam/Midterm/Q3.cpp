#include <bits/stdc++.h>
using namespace std;

#define int long long 
#define endl "\n"
#define file_io freopen("input.txt","r",stdin);freopen("output.txt","w",stdout)
#define fastio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define pb push_back
#define PI 3.14159
#define pii pair<int,int>


const int mod = 1000000007, p = 1000000;
int mark[p + 100] = {0}, 
un[p + 100] = {0}, ans = 1, num;
int32_t main()
{
    for (int i = 2; i * i <= p; i++)
    {
        for (int k = i + i; k <= p; k += i)
        mark[k] = 1;
    }
    int t = 0;
    for (int i = 2; i <= p; i++)
    {
        if (mark[i] == 0)
        {
            un[t] = i;
            t++;
        }
    }
    int a, b;
    cin >> a >> b;
    for (int i = 0; i < t; i++)
    {
        num = 0;
        for (int k = un[i]; k <= a; k += un[i])
        {
            int r = k;
            while ((r / un[i]) % un[i] == 0)
            {
                r = r / un[i];
                num--;
            }num--;
        }
        for (int k = un[i]; k <= b; k += un[i])
        {
            int r = k;
            while ((r / un[i]) % un[i] == 0)
            {
                r = r / un[i];
                num++;
            }
                num++;
        }
        ans = ans * (num + 1ll) % mod;
        if (un[i] > b)
            break;
    }
    cout << ans << endl;
}