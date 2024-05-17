#include <bits/stdc++.h>
using namespace std;

#define int long long 
#define endl "\n"
// #define file_io freopen("input.txt","r",stdin);freopen("output.txt","w",stdout)
#define fastio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)

int32_t main()
{
    string a ,b;
    cin >> a >> b;
    int len_a = a.length();
    int len_b = b.length();
    int index_b = 0 , index_a = 0 , mark = 0;
    for (int i = 0; i < len_a ; i++){
        for (int j = 0; j < len_b ; j++)
        {
            if (a[i] == b[j])
            {
                index_b = j;
                index_a = i;
                mark = 1;
                break;
            }
        }
        if (mark == 1)
        {
            break;
        }
    }
    for (int h = 0; h < len_b ; h++){
        if (h == index_b)
        {
            cout << a << endl;
        }
        else
        {
            for (int a = 0; a < len_a ; a++)
            {
                if(a == index_a)
                {
                    cout << b[h];
                }
                else
                {
                    cout << ".";
                }
            }
            cout << endl;
        }
    }
}