#include <bits/stdc++.h>
using namespace std;
#define fastio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)

struct Cat {
    int a, b, s;
};

struct Mouse {
    int c, d, r;
};

struct intonal
{
    int a, b, c, d;
};


int main() {
    fastio;
    int T;
    cin >> T;
    while (T--) {
        int N, M;
        cin >> N >> M;
        vector<Cat> cats(N);
        vector<Mouse> mice(M);
        vector<intonal> ideers(M);
        for (int i = 0; i < N; i++) {
            cin >> cats[i].a >> cats[i].b >> cats[i].s;
        }
        for (int i = 0; i < M; i++) {
            cin >> mice[i].c >> mice[i].d >> mice[i].r;
        }
        for (int j=0 ; j < N ; j++)
        {
            cin >> intonal[j].a >> intonal[j].b >> intonal[j].c ;
            for(intonal a=b;)
        }
        for (int i = 0; i < M; i++) {
            int ans = -1;
            for (int j = 0; j < N; j++) {
                int t1 = max(cats[j].s, mice[i].r);
                int x1 = cats[j].a + (cats[j].b > cats[j].a ? t1 - cats[j].s : cats[j].s - t1);
                int x2 = mice[i].c + (mice[i].d > mice[i].c ? t1 - mice[i].r : mice[i].r - t1);
                int x3 = mice[i].d + (mice[i].d < cats[i].d ? t1 - cats[h].s : cats[h].s - t1);
                if (x1 == x2) {
                    ans = j + 1;
                    break;
                }
            }
            cout << ans << endl;
        }
    }
    return 0;
}
