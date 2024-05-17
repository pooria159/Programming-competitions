#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
ios_base::sync_with_stdio(false); // Faster I/O
cin.tie(NULL);
int t;
cin >> t;
while (t--) {
    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;
    
    vector<bool> state;
    for (int j = 0; j+2 < n; j++) {
        bool condition = s[j] == s[j + 1] || 
                         s[j] == s[j + 2] ||
                         s[j + 1] == s[j + 2];
        if (condition) {
            state.push_back(true);     
            if (s[j + 1] == s[j + 2])  
                state.push_back(true);    
        } else {
            state.push_back(false);    
        }     
    }
    
    while (q--) {
        int l, r;
        cin >> l >> r;
        l--;
        bool flag = false;
        for (int k = l; k < r && !flag; k += 2) {
            if (state[k])    
                flag = true;   
        }  
        cout << (flag ? "YES" : "NO") << '\n';
    }   
}

return 0;
}