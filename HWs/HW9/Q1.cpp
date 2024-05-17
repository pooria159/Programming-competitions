#include <bits/stdc++.h>
using namespace std;
#define int long long
#define uint unsigned long long
#define endl '\n'
#define file_io freopen("input.txt", "r", stdin);freopen("output.txt", "w", stdout)
#define fastio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
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
#define FOOR(i, n , p) for (int i = n ; i < p; i+=2)
#define maxres *max_element
int mod = 1e9 + 7;
const int numeric = 1e5 + 9;
int parent[numeric];
bool visited[numeric];
vector<int> present;
int edg;
stack<int> stk;
int make_pow(int n , int y , int mod){return(!y ? 1 : (y & 1 ? n * make_pow((n * n) % mod , y/2 , mod) % mod : make_pow((n * n) % mod , y/2 , mod) % mod ));}

struct edge{
	int src, dest, weight;
}edges[numeric];
bool cmp(edge x, edge y){return x.weight < y.weight;}
int find(int x){
	if (parent[x] == x)
		return x;
	return parent[x] = find(parent[x]);
}

int union1(int i, int sum){
	int x, y;
	x = find(edges[i].src);
	y = find(edges[i].dest);
	if (x != y) {
		parent[x] = y;
		present.pb(i);
		sum += edges[i].weight;
	}return sum;
}

int union2(int i, int sum){
	int x, y;
	x = find(edges[i].src);
	y = find(edges[i].dest);
	if (x != y) {
		parent[x] = y;
		sum += edges[i].weight;
		edg++;
	}return sum;
}

int32_t main(){
	fastio;
    int v, e;
    cin >> v >> e;
    vector<int> source;
    vector<int> destination;
    vector<int> weights;
	for(int i = 1; i <= v; i++) parent[i] = i;
    for(int i = 0; i < e; i++){
        int a,b,w;
        cin >> a >> b >> w;
        source.pb(a);
        destination.pb(b);
        weights.pb(w);
    }
	for(int i = 0; i < e; i++) {
		edges[i].src = source[i];
		edges[i].dest = destination[i];
		edges[i].weight = weights[i];
	}
	sort(edges, edges + e, cmp);
	int sum = 0;
	for (int i = 0; i < e; i++) sum = union1(i, sum);
	int sec_best_mst = INT_MAX;
	sum = 0;
	for(int j = 0; j < present.size(); j++){
		for(int i = 1; i <= v; i++) parent[i] = i;
			edg = 0;
		for(int i = 0; i < e; i++){
			if (i == present[j])
				continue;
			sum = union2(i, sum);
		}
		if(edg != v - 1) {sum = 0; continue;}
		sec_best_mst > sum ? sec_best_mst = sum : sum=0;
	}
	sec_best_mst == INT_MAX ? cout << "-1" << endl : cout << sec_best_mst << endl;
}
