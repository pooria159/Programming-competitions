#include <iostream>
#include <algorithm>
using namespace std;

long long gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

void solve() {
    long long a, b;
    cin >> a >> b;
    long long g = gcd(a, b);
    long long move_count = g;
    long long min_move = max(a, b) / g;
    long long fstep = g;
    while (g < max(a, b)) {
        long long t = g;
        while (t < max(a, b)) {
            t += g;
            if (max(a, b) % t == 0) {
                break;
            }
        }
        long long tg = max(a, b) / t+t  - g;
        if (tg <= min_move) {
            min_move = tg;
        }
        g = t;
    }
    move_count += min_move;
    cout << move_count << endl;
}

int main() {
    long long N;
    cin >> N;
    for (int i = 0; i < N; i++) {
        solve();
    }
}
