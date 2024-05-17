#include <bits/stdc++.h>

using namespace std;

class Solver {
	string s;
	long long x = 3, m1 = 1e9+7, m2= 1e9+9;
	vector<long long> H1;
	vector<long long> H2;
public:	
	Solver(string s) : s(s) {	
		H1 = precomputeHashes(s, m1);
		H2 = precomputeHashes(s, m2);
	}
	bool ask(int a, int b, int l) {
		long long y1=1;
		for(int i=0; i<l; i++)
			y1= (x* y1) % m1;
		long long y2=1;
		for(int i=0; i<l; i++)
			y2= (x* y2) % m2;
		auto a1 = (H1[a+l] - (H1[a]*y1)) % m1;
		auto a2 = (H2[a+l] - (H2[a]*y2)) % m2;
		auto b1 = (H1[b+l] - (H1[b]*y1)) % m1;
		auto b2 = (H2[b+l] - (H2[b]*y2)) % m2;
		return (a1==b1 && a2==b2);

	}
	vector<long long> precomputeHashes(string input, long long prime) {
		vector<long long> H(s.size()+1);
		H[0] = 0;
		for(int i = 1; i<=s.size(); i++){
			H[i] = ((x*H[i-1])%prime + input[i-1]) % prime;
		}
		return H;
	}
	
};


int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	string s;
	int q;
	cin >> s >> q;
	Solver solver(s);
	for (int i = 0; i < q; i++) {
		int a, b, l;
		cin >> a >> b >> l;
		cout << (solver.ask(a, b, l) ? "Yes\n" : "No\n");
	}
}
