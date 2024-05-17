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


int check(int n)
{
    int d = n - (n % 100) + 90;
    return d;
}

int convertdj(int n)
{
    return (n % 100) - (n % 10);
}

int glck(int n) {
    int min_x = 9;
    int max_x = 0;
    if (n < 10){
        return -1;
    }
    while (n > 0) {
        int ten = n % 10;
        if (ten < min_x){
            min_x = ten;
        }
        if (ten > max_x){
            max_x = ten;
        }
        n = n / 10;
    }
    return max_x - min_x;
}

int32_t main() {
    fastio;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int l, r;
        cin >> l >> r;
        int luck = 0;
        if (r - l >= 100) {
            int ln = check(l);
            if (ln >= l) {
                cout << ln << endl;
                continue;
            }
            else {
                int lr = check(r);
                if (lr > r) {
                    lr -= 100;
                }
                cout << lr << endl;
                continue;
            }
        }
        int mx = -1;
        int mn = l;
        for (int j = l; j <= r; j++) {
            int lck = glck(j);
            if (lck > mx) {
                mx = lck;
                mn = j;
            }
            if (lck == 9) {
                break;
            }
        }
        cout << mn << endl;
    }
}

