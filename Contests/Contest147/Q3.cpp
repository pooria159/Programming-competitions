#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define pii pair<int, int>
#define vi vector<int>
#define vpii vector<pair<int, int>>
#define all(x) x.begin(), x.end()
#define sz(x) (int)x.size()
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define repp(i, a, b) for (int i = a; i >= b; i--)
#define fastio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
const int mod = 1e9 + 7;
const int N = 2e5 + 5;
int n, t, a[N], b[N];

int32_t main() {
    fastio;
    int t;
    cin >> t;
    int a[t] = {0};
    for(int i = 0; i < t; i++){
        string str;
        cin >> str;
        if(str.length() == 1){a[i] = 0;continue;}
        char tmp = str[0];bool mark = false;
        for(int j = 1; j < str.length(); j++){
            if(tmp != str[j]){
                mark = true;
                break;
            }
        }
        if(mark == false){a[i] = 0;continue;}
        int mi = INT_MAX;
        for (char c = 'a'; c <= 'z'; c++){
            if(str.find(c) != string::npos){
                vector<int> res;
                int change = 1; int max_ch = change;
                for(int j = 0; j < str.length(); j++){
                    if(str[j] != c){
                        if(!res.empty() && res.back() == j - 1)change+=1;
                        else if(!res.empty() && res.back() != j - 1){
                            max_ch = max(change, max_ch); change = 1;
                        }
                        res.push_back(j);
                    }
                }
                max_ch = max(change, max_ch); mi = min(mi, max_ch);
            }
        }
        a[i] = (log2(mi) / log2(2) + 1);
    }
    for (int i = 0; i < t; i++)cout << a[i] << endl;
}