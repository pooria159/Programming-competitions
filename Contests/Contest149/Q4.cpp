#include <bits/stdc++.h>
using namespace std;
#define int long long
#define uint unsigned long long
#define endl '\n'
#define file_io                       \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout)
#define fastio               \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0)
#define ff first
#define pb push_back
#define ss second
#define mk make_pair
#define pii pair<int, int>
#define ABS(n) ((n) < 0 ? -(n) : (n))
#define SORT(v) sort(v.begin(), v.end())
#define REV(v) reverse(v.begin(), v.end())
#define SQR(a) ((a) * (a))
#define FOR(i, n, p) for (int i = n; i < p; i++)
#define ROF(i, n, p) for (int i = p - 1; i > n; i--)
#define FOOR(i, n, p) for (int i = n; i < p; i += 2)
#define maxres *max_element
int mod = 1e9 + 7;
const int numeric = 1e5 + 9;
int parent[numeric];
bool visited[numeric];
vector<int> present;
int edg;
stack<int> stk;
int make_pow(int n, int y, int mod) { return (!y ? 1 : (y & 1 ? n * make_pow((n * n) % mod, y / 2, mod) % mod : make_pow((n * n) % mod, y / 2, mod) % mod)); }


void resuly(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    if (n % 2 == 1){
        cout << "-1" << endl;
        return;
    }
    vector<char> tmp(s.begin(), s.end());
    int tt = 0 ,rc = 0 ,cc = 0;
    bool check = false;
    int state_is_good = (s[0] == '(') ? 1 : 2;
    for (int i = 0; i < n; i++){
        char d = s[i];
        if (d == '('){
            tt++;
            if (cc == 0){
                if (state_is_good != 1) check = true;
                state_is_good = 1;
            }
            tmp[i] = state_is_good + '0';
            (state_is_good == 1) ? cc++ : cc--;
        }
        else{
            rc++;
            if (cc == 0){
                if (state_is_good != 2) check = true;
                state_is_good = 2;
            }
            tmp[i] = state_is_good + '0';
            (state_is_good == 2)? cc++ : cc--;
        }
    }
    if (tt != rc){
        cout << "-1" << endl;
        return;
    }
    cout << (check ? "2" : "1") << endl;
    if (check){
        for (char c : tmp) cout << c << " ";
        cout << endl;
    }
    else
    {
        for (int i = 0; i < n; i++) cout << "1 ";
        cout << endl;
    }
}

int32_t main()
{
    fastio;
    int N;
    cin >> N;
    for (int i = 0; i < N; i++) resuly();
}