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
#define int long long
int mini(int x , int y){
    if(x > y)
        return y;
     return x;
}

struct Node {
    int sum;
    int prefix_sum;
    int suffix_sum;
    int min_sum;
};

vector<int> arr;
vector<Node> seg_tree;

Node combine_nodes(Node left, Node right) {
    Node res;
    res.sum = left.sum + right.sum;
    res.prefix_sum = mini(left.prefix_sum, left.sum + right.prefix_sum);
    res.suffix_sum = mini(right.suffix_sum, right.sum + left.suffix_sum);
    res.min_sum = mini(mini(left.min_sum, right.min_sum) , left.suffix_sum + right.prefix_sum);
    return res;
}

void build_tree(int idx, int start, int end) {
    if (start == end) {
        seg_tree[idx] = {arr[start], arr[start], arr[start], mini(0, arr[start])};
    } else {
        int mid = (start + end) / 2;
        build_tree(2 * idx + 1, start, mid);
        build_tree(2 * idx + 2, mid + 1, end);
        seg_tree[idx] = combine_nodes(seg_tree[2 * idx + 1], seg_tree[2 * idx + 2]);
    }
}

void update_tree(int idx, int pos, int val, int start, int end) {
    if (start == end) {
        arr[pos] = val;
        seg_tree[idx] = {val, val, val, mini(0, val)};
    } else {
        int mid = (start + end) / 2;
        if (pos <= mid) {
            update_tree(2 * idx + 1, pos, val, start, mid);
        } else {
            update_tree(2 * idx + 2, pos, val, mid + 1, end);
        }
        seg_tree[idx] = combine_nodes(seg_tree[2 * idx + 1], seg_tree[2 * idx + 2]);
    }
}

Node query_tree(int idx, int ql, int qr, int start, int end) {
    if (ql <= start && end <= qr) {
        return seg_tree[idx];
    }
    int mid = (start + end) / 2;
    if (qr <= mid) {
        return query_tree(2 * idx + 1, ql, qr, start, mid);
    }
    if (ql > mid) {
        return query_tree(2 * idx + 2, ql, qr, mid + 1, end);
    }
    Node left = query_tree(2 * idx + 1, ql, qr, start, mid);
    Node right = query_tree(2 * idx + 2, ql, qr, mid + 1, end);
    return combine_nodes(left, right);
}

int32_t main() {
    int n, q;
    cin >> n >> q;
    arr.resize(n);
    seg_tree.resize(4 * n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    build_tree(0, 0, n - 1);
    for (int i = 0; i < q; i++) {
        int query_type;
        cin >> query_type;
        if (query_type == 1) {
            int l, r;
            cin >> l >> r;
            l--; r--;
            cout << query_tree(0, l, r, 0, n-1).min_sum << endl;
        } else if (query_type == 2) {
            int pos, val;
            cin >> pos >> val;
            pos--;
            update_tree(0, pos, val, 0, n-1);
        }
    }
}