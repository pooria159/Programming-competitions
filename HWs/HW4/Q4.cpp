#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"
#define file_io freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout)
#define fastio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define pb push_back
#define PI 3.14159
#define pii pair<int, int>
int mod = pow(10,9)+7;
int maxn = pow(10,5)+7;
int minx  = -1*pow(10,5)+7;
int mi = -1;


int32_t main(){
    fastio;
    int n, k , ans=0 , res=0;
    cin >> n >> k;
    int a[k];
    for(int i = 0; i < k; i++)cin >> a[i];
    vector<vector<int>> matrix1(k+100, vector<int>(k+100)) , matrix2(k+100, vector<int>(k+100));
    for(int i = 0; i < k; i++){
        for(int j = 0; j < k-i; j++){
            if(i == 0){matrix1[j][j+i] = a[j];continue;}
            int temp = minx;
            matrix1[j][j+i] = matrix1[j][j] + matrix1[j+1][j+i];
            for(int h = j; h < j+i; h++){
                ans = matrix2[j][h] + matrix2[h+1][j+i] + matrix1[j][j+i];
                (ans < temp||temp==minx) ? temp = ans:1;
            }matrix2[j][j+i] = temp;
        }
    }
    res = matrix2[0][k-1];
    cout << matrix2[0][k-1] << endl;
}

