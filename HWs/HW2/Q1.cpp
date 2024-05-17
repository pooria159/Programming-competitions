#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

bool is_standard(string s) {
    int balance = 0;
    for (char c : s) {
        if (c == '(') {
            balance++;
        } else if (c == ')') {
            if (balance == 0) {
                return false;
            }
            balance--;
        }
    }
    return balance == 0;
}

void generate_combinations(string s, int i, const vector<string>& parentheses, set<string>& standard_parentheses) {
    if (i == parentheses.size()) {
        if (is_standard(s)) {
            standard_parentheses.insert(s);
        }
    } else {
        generate_combinations(s, i + 1, parentheses, standard_parentheses);
        generate_combinations(s + parentheses[i], i + 1, parentheses, standard_parentheses);
    }
}

int main() {
    int n;
    cin >> n;
    vector<string> parentheses(n);
    for (int i = 0; i < n; i++) {
        cin >> parentheses[i];
    }
    set<string> standard_parentheses;
    generate_combinations("", 0, parentheses, standard_parentheses);
    for (const string& s : standard_parentheses) {
        cout << s << endl;
    }
    return 0;
}
