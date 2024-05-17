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
#define ABS(x) ((x) < 0 ? -(x) : (x))
#define SORT(v) sort(v.begin(), v.end())
#define REV(v) reverse(v.begin(), v.end())
#define SQR(a) ((a) * (a))
#define FOR(i, x, p) for (int i = x; i < p; i++)
#define ROF(i, x, p) for (int i = p - 1; i > x; i--)
#define FOOR(i, x , p) for (int i = x ; i < p; i+=2)
#define maxres *max_element

vector<int> HashTable(string s, int prime, int x) {
    vector<int> hash_table(s.size() + 1);
    hash_table[0] = 0;
    FOR(i, 1, s.size()+1)hash_table[i] = (hash_table[i - 1] * x + s[i - 1]) % prime;
    return hash_table;
}

int HashValue(vector<int> hash_table, int prime, int x, int start, int length) {
    int y = pow(x, length) % prime;
    int hash_value = (hash_table[start + length] - y * hash_table[start]) % prime;
    hash_value < 0 ? hash_value += prime : 1;
    return hash_value;
}

string AreEqual(vector<int> table1, vector<int> table2, int prime1, int prime2, int x, int a, int b, int c) {
    int a_hash1 = HashValue(table1, prime1, x, a, c);
    int a_hash2 = HashValue(table2, prime2, x, a, c);
    int b_hash1 = HashValue(table1, prime1, x, b, c);
    int b_hash2 = HashValue(table2, prime2, x, b, c);
    return (a_hash1 == b_hash1 && a_hash2 == b_hash2) ? "Yes" : "No";

}

int32_t main() {
    string s;cin >> s;
    int step;
    cin >> step;
    int m = 1e9+7;
    int m2 = 1e9+9;
    int x = 3;
    vector<int> hash_table1 = HashTable(s, m, x);
    vector<int> hash_table2 = HashTable(s, m2, x);
    FOR(i,0,step){
        int a, b, c;cin >> a >> b >> c;
        cout << AreEqual(hash_table1, hash_table2, m, m2, x, a, b, c) << endl;
    }
}
