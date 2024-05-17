#include <bits/stdc++.h>
using namespace std;
#define int long long
#define uint unsigned long long
#define endl '\n'
#define file_io freopen("input.txt", "r", stdin);freopen("output.txt", "w", stdout)
#define fastio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define ff first
#define ss second
#define pb push_back
#define mk make_pair
#define pii pair<int, int>
#define ABS(n) ((n) < 0 ? -(n) : (n))
#define SORT(v) sort(v.begin(), v.end())
#define REV(v) reverse(v.begin(), v.end())
#define SQR(a) ((a) * (a))
#define FOR(i, n, p) for (int i = n; i < p; i++)
#define ROF(i, n, p) for (int i = p - 1; i > n; i--)
#define FOOR(i, n , p) for (int i = n ; i < p; i+=2)
#define maxres *max_element
int mod = 1e9 + 7;
const int numeric = 1e7;
vector<int> edges[numeric];
int visited[numeric];
int make_pow(int n , int y , int mod){return(!y ? 1 : (y & 1 ? n * make_pow((n * n) % mod , y/2 , mod) % mod : make_pow((n * n) % mod , y/2 , mod) % mod ));}

void DFS(int v, bool &flag){
    visited[v] = 1;
    for (int i : edges[v]){
        if(visited[i] == 2){
            flag = false;
            return;
        }
        else if(visited[i] == 0){
            DFS(i, flag);
        }
    }
    visited[v] = 2;
}


int32_t main(){
    fastio;
    int v, e, a, b;
    cin >> v >> e;
    FOR(i,1,e+1){
        cin >> a >> b;
        edges[a].pb(b);
    }
    bool flag = true;
    FOR(i,1,v+1){
        FOR(j,1,v+1) visited[j] = 0;
        DFS(i, flag);
        if (!flag) break;  
    }
    (flag) ? cout << "Yes" << endl : cout << "No" << endl;
}