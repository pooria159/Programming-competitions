#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define sorta(A, n) sort(A, A + n)
#define sortv(v) sort(v.begin(), v.end())
typedef long long ll;
typedef vector<long long> v_ll;
typedef pair<long long, long long> p_ll;
typedef map<long long, long long> map_ll;


struct ptuple
{
	ll v;
	ll u;
	ll po;
};


class MinHeap
{
private:
	std::vector<ptuple> heap;

public:
	MinHeap();
	void push(ptuple value);
	ptuple pop();
	ptuple peek();
	bool isEmpty();
	void clear();
};

MinHeap::MinHeap()
{
	heap.clear();
}

void MinHeap::clear(){
	heap.clear();
}

void MinHeap::push(ptuple value)
{
	heap.push_back(value);
	int i = heap.size() - 1;

	// Bubble up the element until it's in the correct position
	while (i > 0 && heap[(i - 1) / 2].po > heap[i].po)
	{
		ptuple temp = heap[(i - 1) / 2];
		heap[(i - 1) / 2] = heap[i];
		heap[i] = temp;
		i = (i - 1) / 2;
	}
}

ptuple MinHeap::pop()
{
	// Return -1 if the heap is empty
	if (heap.size() == 0)
	{
		ptuple r;
		r.u = -1, r.v = -1, r.po = -1;
		return r;
	}

	ptuple value = heap[0];
	heap[0] = heap.back();
	heap.pop_back();

	int i = 0;
	while (i < heap.size())
	{
		int left = 2 * i + 1;
		int right = 2 * i + 2;

		// Find the minimum of the two children
		int min = i;
		if (left < heap.size() && heap[left].po < heap[min].po)
		{
			min = left;
		}
		if (right < heap.size() && heap[right].po < heap[min].po)
		{
			min = right;
		}

		// If the minimum isn't the current node, swap it
		if (min != i)
		{
			ptuple temp = heap[i];
			heap[i] = heap[min];
			heap[min] = temp;
			i = min;
		}
		else
		{
			break;
		}
	}

	return value;
}

ptuple MinHeap::peek()
{
	if (heap.size() == 0)
	{
		ptuple r;
		r.u = -1, r.v = -1, r.po = -1;
		return r;
	}
	return heap[0];
}

bool MinHeap::isEmpty()
{
	return heap.size() == 0;
}


const int maxn = 2e3;
ll powers[maxn];
v_ll graph[maxn];
ll ans = 0;
ll p = 0;
MinHeap heap;
bool visited[maxn];

void f(){
	if(heap.isEmpty()) return;
	while(!heap.isEmpty()){
		auto top = heap.pop();
		auto fath = top.u;
		if(visited[fath]) continue;
		visited[fath] = true;
		if(powers[fath] >= p && top.v != -1){
			ans += (powers[fath] - p + 1);
			p = powers[fath] + 1;
		}
		p += powers[fath];
		for(auto u : graph[fath]){
			if(!visited[u]){
				ptuple r;
				r.v = fath;
				r.u = u;
				r.po = powers[r.u];
				heap.push(r);
			}
		}
	}
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll n, m; cin >> n >> m;
	for(int i = 0; i < n; i++) cin >> powers[i];
	for(int i = 0; i < m; i++){
		ll u, v; cin >> v >> u; u--, v--;
		graph[u].push_back(v), graph[v].push_back(u);
	}
	for(int v = 0; v < n; v++){
		ans = 0;
		p = 0;
		ptuple r; r.v = -1; r.u = v; r.po = -1;
		heap.push(r);
		f();
		heap.clear();
		fill(visited, visited + n, false);
		cout << ans << " ";
	}
	cout << endl;
	// f(n);

	return 0;
}