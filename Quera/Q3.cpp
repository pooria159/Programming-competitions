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

int32_t main()
{
    fastio;
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int r;
        cin >> r;
        unordered_map<char, vector<string>> dict;
        for (int j = 0; j < r; j++) {
            string s;
            cin >> s;
            char first = s[0];
            char last = s[s.length()-1];
            dict[first].push_back(s);
        }
        int len = 0;
        for (auto it1 = dict.begin(); it1 != dict.end(); it1++) {
            char first = it1->first;
            vector<string> v1 = it1->second;
            for (auto it2 = v1.begin(); it2 != v1.end(); it2++) {
                string s1 = *it2;
                char last = s1[s1.length()-1];
                vector<string> v2 = dict[last];
                if (v2.size() > 0) {
                    auto it3 = find(v2.begin(), v2.end(), s1);
                    if (it3 != v2.end()) {
                        v2.erase(it3);
                    }
                    for (auto s2: v2) {
                        len += s2.length();
                        s1 += s2;
                    }
                    dict[first].push_back(s1);
                }
                else {
                    len += s1.length();
                }
            }
        }
        cout << len << endl;
    }
}