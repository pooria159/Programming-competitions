#include <bits/stdc++.h>
using namespace std;
#define int long long
#define uint unsigned long long
#define endl '\n'
#define file_io freopen("input.txt", "r", stdin);freopen("output.txt", "w", stdout)
#define fastio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
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
#define MAXN 100005
int mod = 1e9 + 7;
const int N = 1e5 + 5;
int n, m, a[N];
struct node {
    int sum;
} t[N << 2];
void push_up(int rt) {
    t[rt].sum = min(t[rt << 1].sum, t[rt << 1 | 1].sum);
}
void build(int l, int r, int rt) {
    if (l == r) {
        t[rt].sum = a[l];
        return;
    }
    int mid = (l + r) >> 1;
    build(l, mid, rt << 1);
    build(mid + 1, r, rt << 1 | 1);
    push_up(rt);
}
void update(int p, int v, int l, int r, int rt) {
    if (l == r) {
        t[rt].sum = v;
        return;
    }
    int mid = (l + r) >> 1;
    if (p <= mid)
        update(p, v, l, mid, rt << 1);
    else
        update(p, v, mid + 1, r, rt << 1 | 1);
    push_up(rt);
}
int query(int L, int R, int l, int r, int rt) {
    if (L <= l && R >= r)
        return t[rt].sum;
    int mid = (l + r) >> 1;
    int ans = INT_MAX;
    if (L <= mid)
        ans = min(ans, query(L, R, l, mid, rt << 1));
    if (R > mid)
        ans = min(ans, query(L, R,mid + 1,r ,rt << 1 | 1));
    return ans;
}
int32_t main() {
	fastio;
	cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i];
    build(1,n ,1);
    while (m--){
        int op,x,y;
		cin >> op >> x >> y;
        if(op==2){
            update(x,y ,1,n ,1);
        }else{
			cout << query(x,y,1,n ,1) << endl;
        }
    }
}

