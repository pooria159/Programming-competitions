#include <iostream>
using namespace std;

void solve() {
    long long n, k;
    cin >> n >> k;
    if (n % 2 == 0) {
        cout << "Yes" << endl;
        return;
    }
    else {
        long long t = n - k;
        if (t >= 0 && t % 2 == 0) {
            cout << "Yes" << endl;
            return;
        }
    }
    cout << "No" << endl;
    return;
}

int main() {
    long long N;
    cin >> N;
    for (int i = 0; i < N; i++) {
        solve();
    }
    return 0;
}
