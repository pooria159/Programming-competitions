#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int sum_range(int start, int end, int dp_arr[]) {
    if (start == 0) {
        return dp_arr[end];
    }
    return dp_arr[end] - dp_arr[start - 1];
}

string ask_query_range(int start, int end, int arr[]) {
    string qs = "?";
    string l;
    for (int i = start + 1; i <= end + 1; i++) {
        l += to_string(i) + " ";
    }
    return qs + " " + to_string(end - start + 1) + " " + l;
}

string print_ans(int ans) {
    return "! " + to_string(ans);
}

int main() {
    int t;
    scanf("%d", &t);

    while (t--) {
        int n;
        scanf("%d", &n);

        int arr[n];
        for (int i = 0; i < n; i++) {
            scanf("%d", &arr[i]);
        }

        int dp_arr[n];
        dp_arr[0] = arr[0];
        for (int i = 1; i < n; i++) {
            dp_arr[i] = dp_arr[i - 1] + arr[i];
        }

        int start = 0;
        int g_end = n - 1;
        int offset = (g_end - start) / 2;
        int end = start + offset;

        while (g_end - start > 1) {
            cout << ask_query_range(start, end, arr) << endl;
            fflush(stdout);

            int q_in;
            scanf("%d", &q_in);

            if (q_in != sum_range(start, end, dp_arr)) {
                g_end = end;
                offset = (g_end - start) / 2;
                end = start + offset;
            }
            else {
                start = end;
                offset = (g_end - start) / 2;
                end = start + offset;
            }
        }

        cout << ask_query_range(start, start, arr) << endl;
        fflush(stdout);

        int q_in;
        scanf("%d", &q_in);

        if (q_in != sum_range(start, start, dp_arr)) {
            cout << print_ans(start + 1) << endl;
        }
        else {
            cout << print_ans(end + 1) << endl;
        }
        fflush(stdout);
    }

    return 0;
}
